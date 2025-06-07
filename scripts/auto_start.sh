#!/bin/bash 
nm-applet &
sleep 1
aria2c --conf-path=/home/weixi/.config/aria2/aria2.conf -D &
fcitx5 -d &
