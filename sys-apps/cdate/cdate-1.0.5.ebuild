# Copyright 2022 Gentoo Authors
# Distributed under the terms of the GNU General Public License v2

EAPI=8

DESCRIPTION="Show Chinese lunisolar calender date"
HOMEPAGE="http://www.vinoca.org/"

SRC_URI="https://files.vinoca.org/${PN}-${PV}.tar.gz"

LICENSE="BSD"
SLOT="0"
KEYWORDS="~amd64"
src_configure() {
	econf --prefix=/usr/bin
	econf --with-posix-regex
}
src_install() {
	emake DESTDIR="${D}" install
}
