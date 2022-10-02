#ifndef XMONAD_APPLET_H
#define XMONAD_APPLET_H

#include <libgnome-panel/gp-applet.h>

G_BEGIN_DECLS

#define XMONAD_TYPE_APPLET (xmonad_applet_get_type ())
G_DECLARE_FINAL_TYPE (XmonadApplet, xmonad_applet, XMONAD, APPLET, GpApplet)

G_END_DECLS

#endif
