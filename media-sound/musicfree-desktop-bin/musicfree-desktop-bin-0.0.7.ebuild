# Copyright 2025 Your Name
# Distributed under the terms of the GNU General Public License v2

EAPI=8

inherit unpacker desktop

DESCRIPTION=" 插件化、定制化、无广告的免费音乐播放器 "
HOMEPAGE="https://musicfree.catcat.work/"
SRC_URI="https://github.com/maotoumao/MusicFreeDesktop/releases/download/v${PV}/MusicFree-${PV}-linux-amd64.deb"
LICENSE="AGPL 3.0"  # 需确认实际许可证
SLOT="0"
S="${WORKDIR}"
KEYWORDS="~amd64"
MY_PN="musicfree"
RDEPEND="x11-libs/gtk+:3
        x11-libs/libXScrnSaver
        dev-libs/nss
        app-crypt/p11-kit
        dev-libs/libayatana-appindicator
        app-accessibility/at-spi2-core[X]
        app-crypt/libsecret
        x11-libs/libnotify
"

QA_PREBUILT="
		opt/${MY_PN}/chrome-sandbox
		opt/${MY_PN}/libEGL.so
		opt/${MY_PN}/libffmpeg.so
		opt/${MY_PN}/libGLESv2.so
		opt/${MY_PN}/libvk_swiftshader.so
		opt/${MY_PN}/libvulkan.so.1
		opt/${MY_PN}/MusicFree
"


src_install(){
		insinto /opt/${MY_PN}
		doins -r usr/lib/${MY_PN}/*
		dodoc usr/share/doc/${MY_PN}/copyright
		insinto /usr/share/pixmaps
		doins -r usr/share/pixmaps/${MY_PN}.png
		domenu usr/share/applications/${MY_PN}.desktop
		local f
		for f in ${QA_PREBUILT}; do
                fperms +x "/${f}"
        done
		fperms u+s /opt/${MY_PN}/chrome-sandbox
		dosym /opt/${MY_PN}/MusicFree /usr/bin/${MY_PN}
}
pkg_postinst(){
		einfo "EN------------------------------------------------------"
		einfo "Installation successful!"
		einfo "No music source by default."
		einfo "Copy the link to use in MusicFree plug-in subscriptions:"
		einfo "********************************************************"
		einfo "https://musicfreepluginshub.2020818.xyz/plugins.json"
		einfo "********************************************************"
		einfo "This aggregation of plug-in interface more, a "
		einfo "subscription is enough, remember to delete the original"
		einfo "subscription and click the top right menu to uninstall"
		einfo "all plug-ins to avoid conflict."
		einfo "ZH------------------------------------------------------"
		einfo "安装成功！"
		einfo "默认无音乐源。"
		einfo "复制下面的链接在 MusicFree 插件订阅中使用："
		einfo "********************************************************"
		einfo "https://musicfreepluginshub.2020818.xyz/plugins.json"
		einfo "********************************************************"
		einfo "这个聚合的插件接口比较多，一个订阅就够用，记得删除原有订"
		einfo "阅和点击右上角菜单的卸载全部插件以免冲突。"
		einfo "--------------------------------------------------------"
}

