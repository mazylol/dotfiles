if [ -f /etc/bashrc ]; then
  . /etc/bash.bashrc
fi

export PATH=/home/mazy/.cargo/bin/:/home/mazy/.local/share/gem/ruby/3.0.0/bin/:$PATH
export EDITOR=nvim

alias btw='neofetch --source /home/mazy/Documents/ascii/altarch | lolcat'
alias at='alacritty-themes' 
alias grep='grep --color=auto'
alias obsconvert='f() { ffmpeg -i "$1" -vcodec mjpeg -q:v 2 -acodec pcm_s16be -q:a 0 -f mov "$2"; unset -f f; }; f'
alias startcam='gphoto2 --stdout --capture-movie | ffmpeg \
-hwaccel nvdec \
-c:v mjpeg_cuvid \
-i - \
-vcodec rawvideo \
-pix_fmt yuv420p \
-threads 0 \
-f v4l2 /dev/video0
'
alias ls='exa --icons'
alias config='git --git-dir $HOME/.dotfiles --work-tree=$HOME'

export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"  # This loads nvm
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"  # This loads nvm bash_completion

pfetch

export PNPM_HOME="/home/mazy/.local/share/pnpm"
export PATH="$PNPM_HOME:$PATH"
. "$HOME/.cargo/env"
