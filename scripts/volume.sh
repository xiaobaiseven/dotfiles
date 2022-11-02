#!/bin/bash
VOL_STATUS=$(amixer sget Master | tail -n 1 | awk '{print $6;}')
VOL=$(amixer sget Master | tail -n1 | sed -r "s/.*\[(.*)%\].*/\1/")
if [ "$VOL_STATUS" = "[off]" ]; then
    printf "🔇"
else 
    if [ "$VOL" -eq 0 ]; then
        printf "🔇"
    elif [ "$VOL" -gt 1 ] && [ "$VOL" -le 33 ]; then
        printf "🔈%s%%" "$VOL"
    elif [ "$VOL" -gt 33 ] && [ "$VOL" -le 66 ]; then
        printf "🔉%s%%" "$VOL"
    else
        printf "🔊%s%%" "$VOL"
    fi
fi
