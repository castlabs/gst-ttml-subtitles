/* GStreamer
 * Copyright (C) <1999> Erik Walthinsen <omega@cse.ogi.edu>
 * Copyright (C) 2004 Ronald S. Bultje <rbultje@ronald.bitfreak.net>
 * Copyright (C) 2006 Tim-Philipp Müller <tim centricular net>
 * Copyright (C) <2015> British Broadcasting Corporation <dash@rd.bbc.co.uk>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "parser/gstttmlparse.h"
#include "renderer/gstttmlrender.h"

GST_DEBUG_CATEGORY (ttml_parse_debug);
GST_DEBUG_CATEGORY (ttmlrender);

static gboolean
plugin_init (GstPlugin * plugin)
{
  if (!gst_type_find_register (plugin, "ttmlparse_typefind", GST_RANK_MARGINAL,
        gst_ttmlparse_type_find, "srt,sub,mpsub,mdvd,smi,txt,dks,ttml",
        SUB_CAPS, NULL, NULL))
  return FALSE;

  if (!gst_element_register (plugin, "clttmlparse", GST_RANK_PRIMARY, GST_TYPE_TTMLPARSE))
    return FALSE;
  if (!gst_element_register (plugin, "clttmlrender", GST_RANK_PRIMARY, GST_TYPE_TTML_RENDER))
    return FALSE;

  GST_DEBUG_CATEGORY_INIT (ttml_parse_debug, "clttmlparse", 0, "castLabs TTML parser");
  GST_DEBUG_CATEGORY_INIT (ttmlrender, "clttmlrender", 0, "castLabs TTML renderer");

  return TRUE;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    clttmlsubs,
    "castLabs TTML1 subtitle handling",
    plugin_init, VERSION, "LGPL", "gst-ttml", "https://castlabs.com")
