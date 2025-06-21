# Copyright 2025 Your Name
# Distributed under the terms of the GNU General Public License v2

EAPI=8

inherit unpacker desktop

DESCRIPTION="高颜值的第三方网易云播放器；支持流媒体音乐"
HOMEPAGE="https://github.com/stark81/VutronMusic"
SRC_URI="https://github.com/stark81/VutronMusic/releases/download/v${PV}/VutronMusic-${PV}_linux_amd64.deb"
LICENSE="AGPL 3.0"
SLOT="0"
S="${WORKDIR}"
KEYWORDS="~amd64"
MY_PN="VutronMusic"
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
                opt/${MY_PN}/chrome_crashpad_handler
                opt/${MY_PN}/libEGL.so
                opt/${MY_PN}/libffmpeg.so
                opt/${MY_PN}/libGLESv2.so
                opt/${MY_PN}/libvk_swiftshader.so
                opt/${MY_PN}/libvulkan.so.1
                opt/${MY_PN}/vutron
"
src_prepare(){
        default
        unpack usr/share/doc/vutronmusic/changelog.gz
        sed -i 's/Audio/AudioVideo/' usr/share/applications/vutron.desktop || die
        rm opt/${MY_PN}/{LICENSE.electron.txt,LICENSES.chromium.html} || die
}

src_install(){
                insinto /opt/${MY_PN}
                doins -r opt/${MY_PN}/*
                dodoc changelog
                insinto /usr/share/applications
                doins -r usr/share/applications/vutron.desktop
				for si in 16 32 48 64 128 256 512 1024; do
                	doicon -s ${si} usr/share/icons/hicolor/${si}x${si}/apps/vutron.png
        		done
                local f
                for f in ${QA_PREBUILT}; do
                	fperms +x "/${f}"
        		done
                fperms u+s /opt/${MY_PN}/chrome-sandbox
                dosym /opt/${MY_PN}/vutron /usr/bin/${MY_PN}
}
