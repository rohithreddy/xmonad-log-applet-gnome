#include "config.h"
#include "xmonad-applet.h"

#include <dbus/dbus-glib.h>

struct _XmonadApplet
{
  GpApplet    parent;

  GtkWidget  *label;

  DBusGProxy *proxy;
};

G_DEFINE_TYPE (XmonadApplet, xmonad_applet, GP_TYPE_APPLET)

static void
signal_handler (DBusGProxy   *obj,
                const char   *msg,
                XmonadApplet *self)
{
  gtk_label_set_markup (GTK_LABEL (self->label), msg);
}

static void
set_up_dbus_transfer (XmonadApplet *self)
{
  GError *error;
  DBusGConnection *connection;

  error = NULL;
  connection = dbus_g_bus_get (DBUS_BUS_SESSION, &error);

  if (connection == NULL)
    {
      g_printerr ("Failed to open connection: %s\n", error->message);
      g_error_free (error);
      return;
    }

  self->proxy = dbus_g_proxy_new_for_name (connection,
                                           "org.xmonad.Log",
                                           "/org/xmonad/Log",
                                           "org.xmonad.Log");

  dbus_g_proxy_add_signal (self->proxy,
                           "Update",
                           G_TYPE_STRING,
                           G_TYPE_INVALID);

  dbus_g_proxy_connect_signal (self->proxy,
                               "Update",
                               (GCallback) signal_handler,
                               self,
                               NULL);
}

static void
xmonad_applet_constructed (GObject *object)
{
  XmonadApplet *self;

  self = XMONAD_APPLET (object);

  G_OBJECT_CLASS (xmonad_applet_parent_class)->constructed (object);

  self->label = gtk_label_new ("Waiting for Xmonad...");
  gtk_container_add (GTK_CONTAINER (self), self->label);
  gtk_widget_show (self->label);

  gtk_label_set_ellipsize (GTK_LABEL (self->label), PANGO_ELLIPSIZE_END);
  gtk_label_set_use_markup (GTK_LABEL (self->label), TRUE);
  // gtk_widget_set_halign(GTK_MISC (self->label), GTK_ALIGN_START);
  gtk_label_set_xalign (GTK_LABEL (self->label), 0.0);
  // gtk_misc_set_alignment (GTK_MISC (self->label), 0.0, 0.5);
  set_up_dbus_transfer (self);
}

static void
xmonad_applet_finalize (GObject *object)
{
  XmonadApplet *self;

  self = XMONAD_APPLET (object);

  g_clear_object (&self->proxy);

  G_OBJECT_CLASS (xmonad_applet_parent_class)->finalize (object);
}

static void
xmonad_applet_class_init (XmonadAppletClass *self_class)
{
  GObjectClass *object_class;

  object_class = G_OBJECT_CLASS (self_class);

  object_class->constructed = xmonad_applet_constructed;
  object_class->finalize = xmonad_applet_finalize;
}

static void
xmonad_applet_init (XmonadApplet *self)
{
  GpAppletFlags flags;

  flags = GP_APPLET_FLAGS_EXPAND_MAJOR |
          GP_APPLET_FLAGS_EXPAND_MINOR |
          GP_APPLET_FLAGS_HAS_HANDLE;

  gp_applet_set_flags (GP_APPLET (self), flags);
}