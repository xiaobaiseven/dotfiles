#!/bin/sh
dwm_get_music_info(){
	      ARTIST=$(playerctl metadata artist)
        TITLE=$(playerctl metadata title)
				STATUS=$(playerctl status)
				SEP=""

				if [ "$STATUS" = "Playing" ]; then
							STATUS="📡"
							SEP="-"
							if [ "$ARTIST" = "" ];then
								INFO="$STATUS""$TITLE "
							else
								INFO="$STATUS""$ARTIST""$SEP""$TITLE "
							fi
						elif [ "$STATUS" = "Paused" ]; then	
							STATUS="🔕"
							SEP="-"
							if [ "$ARTIST" = "" ];then
								INFO="$STATUS""$TITLE "
							else
								INFO="$STATUS""$ARTIST""$SEP""$TITLE "
							fi
						else
							INFO=""
        fi
				echo ${INFO:0:35}
}
dwm_get_music_info
