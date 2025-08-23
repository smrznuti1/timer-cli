# Maintainer: GreyXor <greyxor@protonmail.com>
# Contributor: Drew DeVault <sir@cmpwn.com>
pkgname=timer-cli
pkgver=0.0.1
pkgrel=1
pkgdesc='Simpe CLI Timer tool.'
arch=('x86_64')
depends=(
    "make"
    "clang"
)
# makedepends=()
# optdepends=()
# provides=()
# conflicts=()
# install="${pkgname}.install"
source=("complete.oga"
    "main.c"
    "Makefile")
b2sums=('SKIP'
    'SKIP'
    'SKIP')

prepare() {
    make clean
}

build() {
    make
}

package() {
    mv ./timer "$pkgdir"
    install -Dm644 complete.oga "${pkgname}/usr/share/sounds/complete.oga"
}
