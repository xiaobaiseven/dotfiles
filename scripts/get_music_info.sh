#!/bin/sh
dwm_get_music_info(){
	      ARTIST=$(playerctl metadata artist)
        TITLE=$(playerctl metadata title)
				STATUS=$(playerctl status)
				SEP=""
				if [ "$STATUS" = "Playing" ]; then
                STATUS="▶"
								SEP="-"
								echo "$STATUS" "$ARTIST" "$SEP" "$TITLE "
						elif [ "$STATUS" = "Paused" ]; then	
								STATUS="⏸"
								SEP="-"
								echo "$STATUS" "$ARTIST" "$SEP" "$TITLE "
            else
								STATUS=""
								echo ""
            fi
}
dwm_get_music_info
