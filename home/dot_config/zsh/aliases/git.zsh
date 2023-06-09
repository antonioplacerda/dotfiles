function git_main_branch() {
  command git rev-parse --git-dir &>/dev/null || return
  local ref
  for ref in refs/{heads,remotes/{origin,upstream}}/{main,trunk,mainline,default}; do
    if command git show-ref -q --verify $ref; then
      echo ${ref:t}
      return
    fi
  done
  echo master
}

function git_current_branch() {
  git branch --show-current
}

alias ga='git add'
alias gaa='git add --all'

alias gb='git branch'
# This is dangerous but learn to live a little
alias gbd='git branch -D'

alias gc='git commit -v'
alias gca='git commit -v --amend'
alias gcam='git commit -a -m'

alias gupa='git pull --rebase --autostash'

alias gcb='git checkout -b' # new branch
alias gco='git checkout' # good old gco
alias gcm='git checkout $(git_main_branch)' # switch to master
alias gcmb='git checkout $(git_main_branch) && git pull --rebase --autostash && git checkout -b' # a brand new branch updated with latest

alias gu='git reset --soft HEAD^' # undo last commit

# pretty logs
alias glol="git log --graph --pretty='%Cred%h%Creset -%C(auto)%d%Creset %s %Cgreen(%ar) %C(bold blue)<%an>%Creset'"
alias glog="git log --graph --pretty=format:'%Cred%h%Creset %an: %s - %Creset %C(yellow)%d%Creset %Cgreen(%cr)%Creset' --abbrev-commit --date=relative"

alias gm='git merge'
alias gma='git merge --abort'
alias gmc='git merge --continue'

# push
alias gp='git push'
alias gpf='git push --force-with-lease'
alias gpsup='git push --set-upstream origin $(git_current_branch)' # my master piece

# rebase
alias gra='git rebase --abort'
alias grc='git rebase --continue'
alias gri='git rebase -i'
alias gr='git rebase'
alias grm='git rebase $(git_main_branch)'

alias gst='git status'

# git stash
alias gsta='git stash'
alias gstl='git stash list'
alias gstd='git stash drop'
alias gstp='git stash pop'
alias gstu='git stash --include-untracked'

function git_fetch_prune_local() {
    git fetch -p 2>&1 | grep '^ - \[deleted\]' | sed 's/.*origin\///' | tr '\n' ' ' | xargs git branch -D
}
alias gfp='git_fetch_prune_local'
