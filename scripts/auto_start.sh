#!/bin/bash 
gentoo-pipewire-launcher &
aria2c --conf-path=/home/weixi/.config/aria2/aria2.conf -D &
fcitx5 -d &
sleep 3
notify-send "$(cdate -g)"
