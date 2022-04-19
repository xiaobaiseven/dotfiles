#!/bin/bash
result=$(ps aux|grep trayer|grep -v grep|grep -v trayer.sh|awk '{print $2}')
if [ "$result" != "" ]; then
	eval "killall trayer"
else
  eval "trayer --edge top --align right --widthtype pixel --width 80  --height 18 --transparent true --tint 10"
fi
