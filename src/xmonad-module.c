#include "config.h"

#include <libgnome-panel/gp-module.h>

#include "xmonad-applet.h"

static GpAppletInfo *
xmonad_get_applet_info (const char *id)
{
  const char *name;
  const char *description;
  const char *icon;
  GpAppletInfo *info;

  name = "Xmonad Log Applet";
  description = "Monitor your Xmonad log";
  icon = "xmonad-log-applet";

  info = gp_applet_info_new (xmonad_applet_get_type, name, description, icon);

  return info;
}

void
gp_module_load (GpModule *module)
{
  gp_module_set_abi_version (module, GP_MODULE_ABI_VERSION);

  gp_module_set_id (module, "xmonad-log-applet");
  gp_module_set_version (module, PACKAGE_VERSION);

  gp_module_set_applet_ids (module, "xmonad-log", NULL);
  gp_module_set_get_applet_info (module, xmonad_get_applet_info);
}
