# matches case insensitive for lowercase
zstyle ':completion:*' matcher-list 'm:{a-z}={A-Z}'

# pasting with tabs doesn't perform completion
zstyle ':completion:*' insert-tab pending

# Uses git's autocompletion for inner commands. Assumes an install of git's
# bash `git-completion` script at $completion below (this is where Homebrew
# tosses it, at least).
completion='$(brew --prefix)/share/zsh/site-functions/_git'

if test -f $completion
then
  source $completion
fi

# The next line updates PATH for the Google Cloud SDK.
if [ -f '/Users/aplacerda/google-cloud-sdk/path.zsh.inc' ]; then . '/Users/aplacerda/google-cloud-sdk/path.zsh.inc'; fi

# The next line enables shell command completion for gcloud.
if [ -f '/Users/aplacerda/google-cloud-sdk/completion.zsh.inc' ]; then . '/Users/aplacerda/google-cloud-sdk/completion.zsh.inc'; fi
