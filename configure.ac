AC_INIT([xmonad-log-applet], [1.0.0])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

AX_IS_RELEASE([git-directory])
AX_CHECK_ENABLE_DEBUG([yes])
AX_COMPILER_FLAGS([WARN_CFLAGS], [WARN_LDFLAGS])

AM_INIT_AUTOMAKE([1.13 no-dist-gzip dist-xz subdir-objects tar-ustar -Wno-portability])
AM_MAINTAINER_MODE([enable])
AM_SILENT_RULES([yes])

LT_INIT([disable-static])

AC_PROG_CC
AC_PATH_PROG([GDBUS_CODEGEN], [gdbus-codegen])
PKG_PROG_PKG_CONFIG([0.19])

LIBGNOME_PANEL_REQUIRED=3.36.0
GLIB_REQUIRED=2.68.0
DBUS_GLIB_REQUIRED=0.111

GNOME_PANEL_MODULES_DIR=`$PKG_CONFIG --variable=modulesdir libgnome-panel`
AC_SUBST([GNOME_PANEL_MODULES_DIR], [$GNOME_PANEL_MODULES_DIR])

PKG_CHECK_MODULES([XMONAD_LOG_APPLET], [
  gio-2.0 >= $GLIB_REQUIRED
  gio-unix-2.0 >= $GLIB_REQUIRED
  libgnome-panel >= $LIBGNOME_PANEL_REQUIRED
  dbus-glib-1 >= $DBUS_GLIB_REQUIRED
])

AC_CONFIG_FILES([
  Makefile

  src/Makefile
])

AC_OUTPUT

echo ""
echo "  Xmonad Log Applet $VERSION"
echo "  `echo Xmonad Log Applet $VERSION | sed "s/./=/g"`"
echo ""
echo "  srcdir ......................: ${srcdir}"
echo ""
echo "  compiler ....................: ${CC}"
echo "  cflags ......................: ${CFLAGS}"
echo ""
echo "  prefix ......................: ${prefix}"
echo "  exec_prefix .................: ${exec_prefix}"
echo "  libdir ......................: ${libdir}"
echo "  sysconfdir ..................: ${sysconfdir}"
echo "  libexecdir ..................: ${libexecdir}"
echo ""
