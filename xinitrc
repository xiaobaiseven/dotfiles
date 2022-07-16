#!/bin/sh

# 设置中文环境
eval "$(dbus-launch --sh-syntax --exit-with-session)"
export LANG=zh_CN.UTF-8


#fcitx5环境变量
export GTK_IM_MODULE=fcitx
export QT_IM_MODULE=fcitx
export XMODIFIERS=\@im=fcitx
export INPUT_METHOD=fcitx
export SDL_IM_MODULE=fcitx
export GLFW_IM_MODULE=ibus



userresources=$HOME/.Xresources
usermodmap=$HOME/.Xmodmap
sysresources=/etc/X11/xinit/.Xresources
sysmodmap=/etc/X11/xinit/.Xmodmap

# merge in defaults and keymaps

if [ -f $sysresources ]; then







    xrdb -merge $sysresources

fi

if [ -f $sysmodmap ]; then
    xmodmap $sysmodmap
fi

if [ -f "$userresources" ]; then







    xrdb -merge "$userresources"

fi

if [ -f "$usermodmap" ]; then
    xmodmap "$usermodmap"
fi

# start some nice programs

if [ -d /etc/X11/xinit/xinitrc.d ] ; then
 for f in /etc/X11/xinit/xinitrc.d/?*.sh ; do
  [ -x "$f" ] && . "$f"
 done
 unset f
fi


# 开机自启动的软件

#设置半透明
picom -cGbf --experimental-backend &
#输入法
fcitx5 -d &
#设置壁纸
feh --recursive --bg-fill Pictures/wallpapers/女神snh48宋昕冉4k高清美女壁纸_无限图库.jpg &
#feh --recursive --bg-fill Pictures/wallpapers/mywallpaper.jpg &

#状态栏
slstatus &
# dwmstatus 2>&1 >/dev/null &
#数字小键盘
numlockx &
exec dwm
