#!/bin/bash
get_cputemp()
{
	cpu_last=($(head -n1 /proc/stat))
  cpu_last_sum="${cpu_last[@]:1}"
  cpu_last_sum=$((${cpu_last_sum// /+}))

  sleep 0.05

  cpu_now=($(head -n1 /proc/stat))
  cpu_sum="${cpu_now[@]:1}"
  cpu_sum=$((${cpu_sum// /+}))

  cpu_delta=$((cpu_sum - cpu_last_sum))
  cpu_idle=$((cpu_now[4]- cpu_last[4]))
  cpu_used=$((cpu_delta - cpu_idle))
  cpu_usage=$((100 * cpu_used / cpu_delta))

  # Keep this as last for our next read
  cpu_last=("${cpu_now[@]}")
  cpu_last_sum=$cpu_sum
	cpu_temp=($(sensors coretemp-isa-0000 | awk -F: '{ print $2 }' | sed -n '3p' | sed -r 's/[^0-9]*([0-9](.*)°C  ).*/\1/'))
	echo " ""${cpu_usage}% "💎" ${cpu_temp}"
}

get_cputemp
