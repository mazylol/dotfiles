if [ -f /etc/bashrc ]; then
  . /etc/bash.bashrc
fi

export GOPATH=$HOME/.go

export PATH=/home/mazy/.cargo/bin/:/home/mazy/.local/share/gem/ruby/3.0.0/bin/:/home/mazy/.emacs.d/bin/:$GOROOT/bin:$GOPATH/bin:$PATH
export EDITOR=nvim

alias \
  btw='neofetch --source /home/mazy/Documents/ascii/altarch | lolcat' \
  at='alacritty-themes' \
  grep='grep --color=auto' \
  obsconvert='f() { ffmpeg -i "$1" -vcodec mjpeg -q:v 2 -acodec pcm_s16be -q:a 0 -f mov "$2"; unset -f f; }; f' \
  ls='exa --icons' \
  config='git --git-dir $HOME/.dotfiles --work-tree=$HOME'

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

export PNPM_HOME="/home/mazy/.local/share/pnpm"
export PATH="$PNPM_HOME:$PATH"
. "$HOME/.cargo/env"

pfetch
