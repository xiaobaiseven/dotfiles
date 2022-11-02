// Modify this file to change what commands output to your statusbar, and
// recompile using the make command.
static const Block blocks[] = {
    /*Icon*/ /*Command*/ /*Update Interval*/ /*Update Signal*/
    //{"", "~/.config/dwmblocks/scripts/",	1,		0},
    {"💾", "~/.config/dwmblocks/scripts/get_disksize.sh", 1, 0},
    {"📀", "~/.config/dwmblocks/scripts/get_cpu_info.sh", 1, 0},
    {"💥", "~/.config/dwmblocks/scripts/get_nvidia_temp.sh", 1, 0},
    {"", "~/.config/dwmblocks/scripts/wlan.sh", 1, 0},
    {"", "~/.config/dwmblocks/scripts/volume.sh", 1, 0},
    {"", "~/.config/dwmblocks/scripts/get_music_info.sh", 1, 0},
    {"🌞", "~/.config/dwmblocks/scripts/get_weather.sh", 3600, 0},
    {"📆", "~/.config/dwmblocks/scripts/get_date.sh  ,1, 0}
    // sets delimeter between status commands. NULL character
    // ('\0') means no delimeter.
};
static char delim[] = " ";
static unsigned int delimLen = 5;
