/* GTK - The GIMP Toolkit
 * Copyright (C) 2011 Red Hat, Inc.
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

#include "config.h"

#include "gtkcssinitialvalueprivate.h"

#include "gtkcssstylepropertyprivate.h"

struct _GtkCssValue {
  GTK_CSS_VALUE_BASE
};

static void
gtk_css_value_initial_free (GtkCssValue *value)
{
  /* Can only happen if the unique value gets unreffed too often */
  g_assert_not_reached ();
}

static GtkCssValue *
gtk_css_value_initial_compute (GtkCssValue             *value,
                               guint                    property_id,
                               GtkStyleProviderPrivate *provider,
                               GtkCssComputedValues    *values,
                               GtkCssComputedValues    *parent_values,
                               GtkCssDependencies      *dependencies)
{
  return _gtk_css_value_compute (_gtk_css_style_property_get_initial_value (_gtk_css_style_property_lookup_by_id (property_id)),
                                 property_id,
                                 provider,
                                 values,
                                 parent_values,
                                 dependencies);
}

static gboolean
gtk_css_value_initial_equal (const GtkCssValue *value1,
                             const GtkCssValue *value2)
{
  return TRUE;
}

static GtkCssValue *
gtk_css_value_initial_transition (GtkCssValue *start,
                                  GtkCssValue *end,
                                  guint        property_id,
                                  double       progress)
{
  return NULL;
}

static void
gtk_css_value_initial_print (const GtkCssValue *value,
                             GString           *string)
{
  g_string_append (string, "initial");
}

static const GtkCssValueClass GTK_CSS_VALUE_INITIAL = {
  gtk_css_value_initial_free,
  gtk_css_value_initial_compute,
  gtk_css_value_initial_equal,
  gtk_css_value_initial_transition,
  gtk_css_value_initial_print
};

static GtkCssValue initial = { &GTK_CSS_VALUE_INITIAL, 1 };

GtkCssValue *
_gtk_css_initial_value_new (void)
{
  return _gtk_css_value_ref (&initial);
}
