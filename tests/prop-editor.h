/* prop-editor.h
 * Copyright (C) 2000  Red Hat, Inc.
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
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include <gtk/gtk.h>

#ifndef __PROP_EDITOR_H__
#define __PROP_EDITOR_H__

G_BEGIN_DECLS

GtkWidget *create_prop_editor (GObject   *object,
			       GType      type);

G_END_DECLS

#endif /* __PROP_EDITOR_H__ */
