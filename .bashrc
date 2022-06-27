if [ -f /etc/bashrc ]; then
  . /etc/bash.bashrc
fi

export GOPATH=$HOME/.go

export PATH=$HOME/.cargo/bin/:$HOME/.local/share/gem/ruby/3.0.0/bin/:$HOME/.emacs.d/bin/:$GOROOT/bin:$GOPATH/bin:$HOME/.yarn/bin:$PATH
export EDITOR=nvim

alias \
  btw='neofetch --source /home/mazy/Documents/ascii/altarch | lolcat' \
  at='alacritty-themes' \
  grep='grep --color=auto' \
  obsconvert='f() { ffmpeg -i "$1" -vcodec mjpeg -q:v 2 -acodec pcm_s16be -q:a 0 -f mov "$2"; unset -f f; }; f' \
  ls='exa --icons' \
  config='git --git-dir $HOME/.dotfiles --work-tree=$HOME' \
  windowz='neofetch --ascii_distro windows'

. "$HOME/.cargo/env"

pfetch
