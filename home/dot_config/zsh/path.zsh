# Just make sure the PATH always starts from scratch and
# only things I want gets added
export PATH="/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"


export PATH="/usr/local/sbin:$ZSH/bin:$HOME/.local/bin:$PATH"
export MANPATH="/usr/local/man:/usr/local/mysql/man:/usr/local/git/man:$MANPATH"

# https://brew.sh/
export PATH="/opt/homebrew/bin:$PATH"
export PATH="/opt/homebrew/sbin:$PATH"
export PATH="/opt/homebrew/opt/sqlite/bin:$PATH"

export GOPATH="$HOME/go"
export PATH="$GOPATH/bin:$PATH"
export GOPRIVATE="bitbucket.org/toggleglobal/*,github.com/toggleglobal/*"
