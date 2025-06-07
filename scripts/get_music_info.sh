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
								echo "$STATUS""$TITLE "
							else
								echo "$STATUS""$ARTIST""$SEP""$TITLE"
							fi
						elif [ "$STATUS" = "Paused" ]; then	
							STATUS="⏯"
							SEP="-"
							if [ "$ARTIST" = "" ];then
								echo "$STATUS""$TITLE"
							else
								echo "$STATUS""$ARTIST""$SEP""$TITLE"
							fi
						else
							STATUS=""
						echo ""
        fi
}
dwm_get_music_info
