#!/bin/bash
files=("$HOME/Pictures/wallpapers"/*)
num=${#files[*]}
for ((i=1; i<=$num-1; i ++))
do
	feh --recursive --bg-fill "${files[$i]}"
	sleep 1m
done
feh --recursive --bg-fill "${files[0]}"
sleep 1m
