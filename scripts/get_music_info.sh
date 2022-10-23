#!/bin/sh
dwm_get_music_info(){
	      ARTIST=$(playerctl metadata artist)
        TITLE=$(playerctl metadata title)
				STATUS=$(playerctl status)
				SEP=""

				if [ "$STATUS" = "Playing" ]; then
							STATUS="▶ 正在播放"
							SEP="-"
							if [ "$ARTIST" = "" ];then
								echo "$STATUS"视频:"$TITLE "
							else
								echo "$STATUS"音乐:"$ARTIST" "$SEP" "$TITLE "
							fi
						elif [ "$STATUS" = "Paused" ]; then	
							STATUS="⏸ 暂停播放"
							SEP="-"
							if [ "$ARTIST" = "" ];then
								echo "$STATUS"视频:"$TITLE "
							else
								echo "$STATUS"音乐:"$ARTIST" "$SEP" "$TITLE "
							fi
						else
							STATUS=""
						echo ""
        fi
}
dwm_get_music_info
