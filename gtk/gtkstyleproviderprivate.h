/* GTK - The GIMP Toolkit
 * Copyright (C) 2011 Benjamin Otte <otte@gnome.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __GTK_STYLE_PROVIDER_PRIVATE_H__
#define __GTK_STYLE_PROVIDER_PRIVATE_H__

#include <glib-object.h>
#include "gtk/gtkcsskeyframesprivate.h"
#include "gtk/gtkcsslookupprivate.h"
#include "gtk/gtkcssmatcherprivate.h"
#include <gtk/gtkenums.h>
#include <gtk/gtksymboliccolor.h>
#include <gtk/gtktypes.h>

G_BEGIN_DECLS

#define GTK_TYPE_STYLE_PROVIDER_PRIVATE          (_gtk_style_provider_private_get_type ())
#define GTK_STYLE_PROVIDER_PRIVATE(o)            (G_TYPE_CHECK_INSTANCE_CAST ((o), GTK_TYPE_STYLE_PROVIDER_PRIVATE, GtkStyleProviderPrivate))
#define GTK_IS_STYLE_PROVIDER_PRIVATE(o)         (G_TYPE_CHECK_INSTANCE_TYPE ((o), GTK_TYPE_STYLE_PROVIDER_PRIVATE))
#define GTK_STYLE_PROVIDER_PRIVATE_GET_INTERFACE(o)  (G_TYPE_INSTANCE_GET_INTERFACE ((o), GTK_TYPE_STYLE_PROVIDER_PRIVATE, GtkStyleProviderPrivateInterface))

typedef struct _GtkStyleProviderPrivateInterface GtkStyleProviderPrivateInterface;
/* typedef struct _GtkStyleProviderPrivate GtkStyleProviderPrivate; */ /* dummy typedef */

struct _GtkStyleProviderPrivateInterface
{
  GTypeInterface g_iface;

  GtkSymbolicColor *    (* get_color)           (GtkStyleProviderPrivate *provider,
                                                 const char              *name);
  GtkCssKeyframes *     (* get_keyframes)       (GtkStyleProviderPrivate *provider,
                                                 const char              *name);
  void                  (* lookup)              (GtkStyleProviderPrivate *provider,
                                                 const GtkCssMatcher     *matcher,
                                                 GtkCssLookup            *lookup);
  GtkCssChange          (* get_change)          (GtkStyleProviderPrivate *provider,
                                                 const GtkCssMatcher     *matcher);

  /* signal */
  void                  (* changed)             (GtkStyleProviderPrivate *provider);
};

GType                   _gtk_style_provider_private_get_type     (void) G_GNUC_CONST;

GtkSymbolicColor *      _gtk_style_provider_private_get_color    (GtkStyleProviderPrivate *provider,
                                                                  const char              *name);
GtkCssKeyframes *       _gtk_style_provider_private_get_keyframes(GtkStyleProviderPrivate *provider,
                                                                  const char              *name);
void                    _gtk_style_provider_private_lookup       (GtkStyleProviderPrivate *provider,
                                                                  const GtkCssMatcher     *matcher,
                                                                  GtkCssLookup            *lookup);
GtkCssChange            _gtk_style_provider_private_get_change   (GtkStyleProviderPrivate *provider,
                                                                  const GtkCssMatcher     *matcher);

void                    _gtk_style_provider_private_changed      (GtkStyleProviderPrivate *provider);

G_END_DECLS

#endif /* __GTK_STYLE_PROVIDER_PRIVATE_H__ */
