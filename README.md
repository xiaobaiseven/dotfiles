# 我的dwm和其他相关软件的配置文件

### make.conf是我的gentoo配置文件,kernel.config是我的内核配置文件，请勿照搬！！！　

## 使用方法
### 需要安装xlib头文件以及imlib2文件库 需要安装一些软件xorg-server xorg-xinit ranger ueberzug gd neovim picom-jonaburg rofi dmenu feh nerd-fonts(需要添加额外的use firecode firemono noto) alacritty chromium alsa-utils alsa-plugins pulseaudio-alsa wqy-zenhei fontawesome lsd (在gentoo中的包名，其他发行版可能略有不同) 
```bash
cd 
git clone https://github.com/xiaobaiseven/dotfiles.git
cd dotfiles
mkdir -v ~/Pictures
mv wallpapers ~/Pictures
cp xinitrc ~/.xinitrc
# 如果你已经有了.config目录,就将其他的所有文件夹移动到~/.config目录下
# 如果没有：
cd 
mv dotfiles .config 
# 编译安装dwm
cd ~/.config/dwm
make
sudo make clean install
# 编译安装ｓｔ
cd ~/.config/st
make
sudo make clean install
# 编译安装slstatus
cd ~/.config/dc-slstatus
make
sudo make clean install
```
### 快捷键使用说明都在config.h文件里面，可以根据自己的使用习惯和需求自行更改
