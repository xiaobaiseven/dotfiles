#!/bin/bash

# Prints out the total disk memory and the availeable memory

get_disk()
{
    #TOTAL_SIZE=$( df -h --total | tail -1 | awk {'printf $2'})
    #USED_SIZE=$(df -h --total | tail -1 | awk {'printf $3'})
    PERCENTAGE=$(df -h --total | tail -1 | awk {'printf $5'})

    #echo  "${USED_SIZE}/${TOTAL_SIZE}($PERCENTAGE)"
    echo  "${PERCENTAGE}"
}

get_disk
