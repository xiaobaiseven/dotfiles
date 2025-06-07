/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/*
 * function            description                     argument (example)
 *
 * battery_perc        battery percentage              battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cpu_perc            cpu usage in percent            NULL
 * cpu_freq            cpu frequency in MHz            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/")
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * separator           string to echo                  NULL
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 */
static const char vol[]         = "[ `amixer sget Master | tail -n 1 | awk '{print $6;}'` = \"[on]\" ] \
                                   && printf \" \uf028 `amixer sget Master | tail -n 1 | awk '{print $5;}' | grep -Po '\\[\\K[^%]*'`%%\" \
                                   || printf '\uf028 \uf05e '";

static const char get_time[] = "date '+%Y年%m月%d日(%A) \uf017 %T'";

static const char get_cpu_temp[] = "sensors coretemp-isa-0000 | awk -F: '{ print $2 }' | sed -n '3p' | sed -r 's/[^0-9]*([0-9](.*)°C  ).*/\\1/'";

static const char get_nvidia_temp[] = "nvidia-settings -q gpucoretemp -t | head -n 1";

static const struct arg args[] = {
	/* function format          argument */
	{cpu_perc, " \uf2db %s%%", NULL},
	//{temp," \uf2c8 %s \u2103", "/sys/class/thermal/thermal_zone0/temp"},
	{run_command, " \uf2c8 %s", get_cpu_temp},
	{ram_perc, "💿 %s%%", NULL},
	{disk_perc, " \uf0a0 %s%%", "/"},
	{run_command, " \uf8c7 %s",get_cpu_temp},
	{netspeed_rx, "\uf063 %s", "enp4s0"},
	{netspeed_tx, " \uf062 %s", "enp4s0"},
	//{ipv4, " \uf26b %s ", "enp4s0"},
	{run_command, "%s ", vol},
	{run_command, "\uf455 %s ", get_time},
};
