# .bash_profile

# Get the aliases and functions
[ -f $HOME/.bashrc ] && . $HOME/.bashrc
. "$HOME/.cargo/env"


# Added by Toolbox App
export PATH="$PATH:/home/mazylol/.local/share/JetBrains/Toolbox/scripts"

export DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
export $(dbus-launch)
source "/home/mazylol/.emsdk/emsdk_env.sh"
