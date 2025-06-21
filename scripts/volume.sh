#!/bin/bash
if wpctl get-volume @DEFAULT_AUDIO_SINK@ | grep -q "MUTED"; then
	echo "🔇"
else
	VOL=$(wpctl get-volume @DEFAULT_AUDIO_SINK@ | awk '{printf "%.0f\n", $2 * 100}')
    	if (( 0 < VOL <= 30 )); then
    		STA="🔈"
	elif (( 30 < VOL <= 60 )); then
    		STA="🔉"
	else 
		STA="🔊"
	fi
	echo "${STA}${VOL}%"
fi
