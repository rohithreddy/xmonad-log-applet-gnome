NULL =

xmonad_log_applet_libdir = $(GNOME_PANEL_MODULES_DIR)
xmonad_log_applet_lib_LTLIBRARIES = xmonad_log_applet.la

xmonad_log_applet_la_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"xmonad-log-applet\" \
	-DG_LOG_USE_STRUCTURED=1 \
	-I$(top_srcdir) \
	$(AM_CPPFLAGS) \
	$(NULL)

xmonad_log_applet_la_CFLAGS = \
	$(XMONAD_LOG_APPLET_CFLAGS) \
	$(WARN_CFLAGS) \
	$(AM_CFLAGS) \
	$(NULL)

xmonad_log_applet_la_SOURCES = \
	xmonad-applet.c \
	xmonad-applet.h \
	xmonad-module.c \
	$(NULL)

xmonad_log_applet_la_LIBADD = \
	$(XMONAD_LOG_APPLET_LIBS) \
	$(NULL)

xmonad_log_applet_la_LDFLAGS = \
	-module -avoid-version \
	$(WARN_LDFLAGS) \
	$(AM_LDFLAGS) \
	$(NULL)

-include $(top_srcdir)/git.mk
