# scripts

#### 介绍
配合dwm使用的脚本




#### 安装教程

dwm的config.h文件中定义启动脚本的快捷键

需要安装trayer来使用系统托盘脚本，安装feh来使用壁纸脚本

#### 使用说明
直接按你在dwm的config.h文件中的dwm快捷键就可以启动脚本

wp-autochange.sh为自启动脚本，将其写到.xinitrc文件中

其他三个脚本为快捷键启动脚本

wp-change.sh是切换壁纸的脚本

suspend.sh是息屏脚本

trayer.sh是系统托盘脚本

壁纸也可以使用py文件设置,

需要给py文件可执行权限，需要指定壁纸目录为~/Pictures/wallpapers/

将壁纸文件保存到上述目录，给py文件执行权限

chmod +x changewp.py

在你的.xinitrc文件内写入下面这行

python -u ~/.config/scripts/changewp.py &

