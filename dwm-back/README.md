这个配置是我自己慢慢配置的

dwm - dynamic window manager
dwm - 动态窗口管理器
============================
dwm is an extremely fast, small, and dynamic window manager for X.
dwm是一个非常快速、精简的动态窗口管理器。

Requirements
使用要求
------------
In order to build dwm you need the Xlib header files.
构建dwm文件需要xlib头文件

Installation
安装
------------
Edit config.mk to match your local setup (dwm is installed into
the /usr/local namespace by default).
编辑config.mk文件设置您的默认安装位置（默认安装在/usr/local目录下）

Afterwards enter the following command to build and install dwm (if
necessary as root):
然后您需要输入并运行以下命令编译安装dwm（需要使用root权限）

    make clean install


Running dwm
运行dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:
将以下行添加到 .xinitrc 中来通过 startx 启动 dwm:
    exec dwm

In order to connect dwm to a specific display, make sure that
the DISPLAY environment variable is set correctly, e.g.:
如果你需要使用多显示器启动 dwm, 你需要设置屏幕变量, 以下是一个例子:
    DISPLAY=foo.bar:1 exec dwm

(This will start dwm on display :1 of the host foo.bar.)
(这样将会启动 dwm 并显示在显示器一上)
In order to display status info in the bar, you can do something
like this in your .xinitrc:
如果你想自定义你的状态栏, 你可以在 .xinitrc 添加行, 以下是一个例子:
    while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
    do
    	sleep 1
    done &
    exec dwm


Configuration
配置文件
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.
dwm的配置是通过创建自定义config.h来完成的
更改完config.def.h文件需要重新编译源代码。
