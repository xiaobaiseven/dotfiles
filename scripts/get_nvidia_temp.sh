#!/bin/bash
get_gputemp()
{
	GPU_TEMP="$(nvidia-settings -q gpucoretemp -t | head -n 1)"
	echo "${GPU_TEMP}°C"
}

get_gputemp
