# Copyright 1999-2022 Gentoo Authors
# Distributed under the terms of the GNU General Public License v2

EAPI=8

inherit savedconfig toolchain-funcs

DESCRIPTION="a dynamic window manager for X11"
HOMEPAGE="https://dwm.suckless.org/"

inherit git-r3
EGIT_REPO_URI="https://github.com/xiaobaiseven/dwm.git"
KEYWORDS="~amd64 ~arm ~arm64 ~ppc ~ppc64 ~riscv ~x86"

LICENSE="MIT"
SLOT="0"
RDEPEND="
	media-libs/fontconfig
	x11-libs/libX11
	>=x11-libs/libXft-2.3.5
	x11-libs/libXinerama
"
DEPEND="
	${RDEPEND}
"
src_prepare() {
        default

        sed -i \
                -e "s/ -Os / /" \
                -e "/^\(LDFLAGS\|CFLAGS\|CPPFLAGS\)/{s| = | += |g;s|-s ||g}" \
                -e "/^X11LIB/{s:/usr/X11R6/lib:/usr/$(get_libdir)/X11:}" \
                -e '/^X11INC/{s:/usr/X11R6/include:/usr/include/X11:}' \
                config.mk || die

        restore_config config.h
}

src_compile() {
        emake CC="$(tc-getCC)" dwm
}

src_install() {
        emake DESTDIR="${D}" PREFIX="${EPREFIX}/usr" install

        exeinto /etc/X11/Sessions
        newexe "${FILESDIR}"/dwm-session2 dwm

        insinto /usr/share/xsessions
        doins "${FILESDIR}"/dwm.desktop

        dodoc README

        save_config config.h
}

