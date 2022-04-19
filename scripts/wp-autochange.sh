#!/bin/bash
files=("$HOME/Pictures/wallpapers"/*)
feh --recursive --bg-fill "${files[0]}"
sleep 1m
while true; do
	/bin/bash ~/.config/scripts/wp-change.sh
	sleep 1m
done
