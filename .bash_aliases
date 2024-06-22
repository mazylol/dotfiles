alias \
  obsconvert='f() { ffmpeg -i "$1" -vcodec mjpeg -q:v 2 -acodec pcm_s16be -threads 12 -q:a 0 -f mov "$2"; unset -f f; }; f' \
  alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"' \
  ls='eza' \
  ll='ls -alF' \
  la='ls -a' \
  l='ls -CF' \
  config='git --git-dir $HOME/.dotfiles --work-tree=$HOME' \
  smallerize='f() { ffmpeg -i "$1" -crf 28 "$2"; unset -f f; }; f' \
  ssdspeed='fio --randrepeat=1 --ioengine=libaio --direct=1 --gtod_reduce=1 --name=test --filename=random_read_write.fio --bs=4k --iodepth=64 --size=1G --readwrite=randrw --rwmixread=80' \
  d='docker' \
  cp='rsync -ah --progress' \
  fnvim='nvim $(fzf)' \
  xblank="sleep 3 ; xset dpms force off" \
  updatemirrors="sudo reflector --latest 5 --protocol https,rsync --sort rate --save /etc/pacman.d/mirrorlist" \
  vim="nvim"

if [ -x /usr/bin/dircolors ]; then
    test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
    #alias ls='eza --icons'
    alias dir='dir --color=auto'
    alias vdir='vdir --color=auto'

    alias grep='grep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias egrep='egrep --color=auto'
fi
