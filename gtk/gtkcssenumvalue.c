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

#include "gtkcssenumvalueprivate.h"

#include "gtkstylepropertyprivate.h"

/* repeated API */

struct _GtkCssValue {
  GTK_CSS_VALUE_BASE
  int value;
  const char *name;
};

static void
gtk_css_value_enum_free (GtkCssValue *value)
{
  g_slice_free (GtkCssValue, value);
}

static GtkCssValue *
gtk_css_value_enum_compute (GtkCssValue             *value,
                            guint                    property_id,
                            GtkStyleProviderPrivate *provider,
                            GtkCssComputedValues    *values,
                            GtkCssComputedValues    *parent_values,
                            GtkCssDependencies      *dependencies)
{
  return _gtk_css_value_ref (value);
}

static gboolean
gtk_css_value_enum_equal (const GtkCssValue *enum1,
                          const GtkCssValue *enum2)
{
  return enum1 == enum2;
}

static GtkCssValue *
gtk_css_value_enum_transition (GtkCssValue *start,
                               GtkCssValue *end,
                               guint        property_id,
                               double       progress)
{
  return NULL;
}

static void
gtk_css_value_enum_print (const GtkCssValue *value,
                          GString           *string)
{
  g_string_append (string, value->name);
}

/* GtkBorderStyle */

static const GtkCssValueClass GTK_CSS_VALUE_BORDER_STYLE = {
  gtk_css_value_enum_free,
  gtk_css_value_enum_compute,
  gtk_css_value_enum_equal,
  gtk_css_value_enum_transition,
  gtk_css_value_enum_print
};

static GtkCssValue border_style_values[] = {
  { &GTK_CSS_VALUE_BORDER_STYLE, 1, GTK_BORDER_STYLE_NONE, "none" },
  { &GTK_CSS_VALUE_BORDER_STYLE, 1, GTK_BORDER_STYLE_SOLID, "solid" },
  { &GTK_CSS_VALUE_BORDER_STYLE, 1, GTK_BORDER_STYLE_INSET, "inset" },
  { &GTK_CSS_VALUE_BORDER_STYLE, 1, GTK_BORDER_STYLE_OUTSET, "outset" },
  { &GTK_CSS_VALUE_BORDER_STYLE, 1, GTK_BORDER_STYLE_HIDDEN, "hidden" },
  { &GTK_CSS_VALUE_BORDER_STYLE, 1, GTK_BORDER_STYLE_DOTTED, "dotted" },
  { &GTK_CSS_VALUE_BORDER_STYLE, 1, GTK_BORDER_STYLE_DASHED, "dashed" },
  { &GTK_CSS_VALUE_BORDER_STYLE, 1, GTK_BORDER_STYLE_DOUBLE, "double" },
  { &GTK_CSS_VALUE_BORDER_STYLE, 1, GTK_BORDER_STYLE_GROOVE, "groove" },
  { &GTK_CSS_VALUE_BORDER_STYLE, 1, GTK_BORDER_STYLE_RIDGE, "ridge" }
};

GtkCssValue *
_gtk_css_border_style_value_new (GtkBorderStyle border_style)
{
  g_return_val_if_fail (border_style < G_N_ELEMENTS (border_style_values), NULL);

  return _gtk_css_value_ref (&border_style_values[border_style]);
}

GtkCssValue *
_gtk_css_border_style_value_try_parse (GtkCssParser *parser)
{
  guint i;

  g_return_val_if_fail (parser != NULL, NULL);

  for (i = 0; i < G_N_ELEMENTS (border_style_values); i++)
    {
      if (_gtk_css_parser_try (parser, border_style_values[i].name, TRUE))
        return _gtk_css_value_ref (&border_style_values[i]);
    }

  return NULL;
}

GtkBorderStyle
_gtk_css_border_style_value_get (const GtkCssValue *value)
{
  g_return_val_if_fail (value->class == &GTK_CSS_VALUE_BORDER_STYLE, GTK_BORDER_STYLE_NONE);

  return value->value;
}

/* PangoStyle */

static const GtkCssValueClass GTK_CSS_VALUE_FONT_STYLE = {
  gtk_css_value_enum_free,
  gtk_css_value_enum_compute,
  gtk_css_value_enum_equal,
  gtk_css_value_enum_transition,
  gtk_css_value_enum_print
};

static GtkCssValue font_style_values[] = {
  { &GTK_CSS_VALUE_FONT_STYLE, 1, PANGO_STYLE_NORMAL, "normal" },
  { &GTK_CSS_VALUE_FONT_STYLE, 1, PANGO_STYLE_OBLIQUE, "oblique" },
  { &GTK_CSS_VALUE_FONT_STYLE, 1, PANGO_STYLE_ITALIC, "italic" }
};

GtkCssValue *
_gtk_css_font_style_value_new (PangoStyle font_style)
{
  g_return_val_if_fail (font_style < G_N_ELEMENTS (font_style_values), NULL);

  return _gtk_css_value_ref (&font_style_values[font_style]);
}

GtkCssValue *
_gtk_css_font_style_value_try_parse (GtkCssParser *parser)
{
  guint i;

  g_return_val_if_fail (parser != NULL, NULL);

  for (i = 0; i < G_N_ELEMENTS (font_style_values); i++)
    {
      if (_gtk_css_parser_try (parser, font_style_values[i].name, TRUE))
        return _gtk_css_value_ref (&font_style_values[i]);
    }

  return NULL;
}

PangoStyle
_gtk_css_font_style_value_get (const GtkCssValue *value)
{
  g_return_val_if_fail (value->class == &GTK_CSS_VALUE_FONT_STYLE, PANGO_STYLE_NORMAL);

  return value->value;
}

/* PangoVariant */

static const GtkCssValueClass GTK_CSS_VALUE_FONT_VARIANT = {
  gtk_css_value_enum_free,
  gtk_css_value_enum_compute,
  gtk_css_value_enum_equal,
  gtk_css_value_enum_transition,
  gtk_css_value_enum_print
};

static GtkCssValue font_variant_values[] = {
  { &GTK_CSS_VALUE_FONT_VARIANT, 1, PANGO_VARIANT_NORMAL, "normal" },
  { &GTK_CSS_VALUE_FONT_VARIANT, 1, PANGO_VARIANT_SMALL_CAPS, "small-caps" }
};

GtkCssValue *
_gtk_css_font_variant_value_new (PangoVariant font_variant)
{
  g_return_val_if_fail (font_variant < G_N_ELEMENTS (font_variant_values), NULL);

  return _gtk_css_value_ref (&font_variant_values[font_variant]);
}

GtkCssValue *
_gtk_css_font_variant_value_try_parse (GtkCssParser *parser)
{
  guint i;

  g_return_val_if_fail (parser != NULL, NULL);

  for (i = 0; i < G_N_ELEMENTS (font_variant_values); i++)
    {
      if (_gtk_css_parser_try (parser, font_variant_values[i].name, TRUE))
        return _gtk_css_value_ref (&font_variant_values[i]);
    }

  return NULL;
}

PangoVariant
_gtk_css_font_variant_value_get (const GtkCssValue *value)
{
  g_return_val_if_fail (value->class == &GTK_CSS_VALUE_FONT_VARIANT, PANGO_VARIANT_NORMAL);

  return value->value;
}

/* PangoWeight */

static const GtkCssValueClass GTK_CSS_VALUE_FONT_WEIGHT = {
  gtk_css_value_enum_free,
  gtk_css_value_enum_compute,
  gtk_css_value_enum_equal,
  gtk_css_value_enum_transition,
  gtk_css_value_enum_print
};

static GtkCssValue font_weight_values[] = {
  { &GTK_CSS_VALUE_FONT_WEIGHT, 1, PANGO_WEIGHT_THIN, "100" },
  { &GTK_CSS_VALUE_FONT_WEIGHT, 1, PANGO_WEIGHT_ULTRALIGHT, "200" },
  { &GTK_CSS_VALUE_FONT_WEIGHT, 1, PANGO_WEIGHT_LIGHT, "300" },
  { &GTK_CSS_VALUE_FONT_WEIGHT, 1, PANGO_WEIGHT_NORMAL, "normal" },
  { &GTK_CSS_VALUE_FONT_WEIGHT, 1, PANGO_WEIGHT_MEDIUM, "500" },
  { &GTK_CSS_VALUE_FONT_WEIGHT, 1, PANGO_WEIGHT_SEMIBOLD, "600" },
  { &GTK_CSS_VALUE_FONT_WEIGHT, 1, PANGO_WEIGHT_BOLD, "bold" },
  { &GTK_CSS_VALUE_FONT_WEIGHT, 1, PANGO_WEIGHT_ULTRABOLD, "800" },
  { &GTK_CSS_VALUE_FONT_WEIGHT, 1, PANGO_WEIGHT_HEAVY, "900" }
};

GtkCssValue *
_gtk_css_font_weight_value_new (PangoWeight font_weight)
{
  guint i;
  gint w;

  w = ((font_weight + 50) / 100) * 100;

  for (i = 0; i < G_N_ELEMENTS (font_weight_values); i++)
    {
      if (font_weight_values[i].value == w)
        return _gtk_css_value_ref (&font_weight_values[i]);
    }

  g_return_val_if_reached (NULL);
}

GtkCssValue *
_gtk_css_font_weight_value_try_parse (GtkCssParser *parser)
{
  guint i;

  g_return_val_if_fail (parser != NULL, NULL);

  for (i = 0; i < G_N_ELEMENTS (font_weight_values); i++)
    {
      if (_gtk_css_parser_try (parser, font_weight_values[i].name, TRUE))
        return _gtk_css_value_ref (&font_weight_values[i]);
    }
  /* special cases go here */
  if (_gtk_css_parser_try (parser, "400", TRUE))
    return _gtk_css_value_ref (&font_weight_values[3]);
  if (_gtk_css_parser_try (parser, "700", TRUE))
    return _gtk_css_value_ref (&font_weight_values[6]);

  return NULL;
}

PangoWeight
_gtk_css_font_weight_value_get (const GtkCssValue *value)
{
  g_return_val_if_fail (value->class == &GTK_CSS_VALUE_FONT_WEIGHT, PANGO_WEIGHT_NORMAL);

  return value->value;
}

/* GtkCssArea */

static const GtkCssValueClass GTK_CSS_VALUE_AREA = {
  gtk_css_value_enum_free,
  gtk_css_value_enum_compute,
  gtk_css_value_enum_equal,
  gtk_css_value_enum_transition,
  gtk_css_value_enum_print
};

static GtkCssValue area_values[] = {
  { &GTK_CSS_VALUE_AREA, 1, GTK_CSS_AREA_BORDER_BOX, "border-box" },
  { &GTK_CSS_VALUE_AREA, 1, GTK_CSS_AREA_PADDING_BOX, "padding-box" },
  { &GTK_CSS_VALUE_AREA, 1, GTK_CSS_AREA_CONTENT_BOX, "content-box" }
};

GtkCssValue *
_gtk_css_area_value_new (GtkCssArea area)
{
  guint i;

  for (i = 0; i < G_N_ELEMENTS (area_values); i++)
    {
      if (area_values[i].value == area)
        return _gtk_css_value_ref (&area_values[i]);
    }

  g_return_val_if_reached (NULL);
}

GtkCssValue *
_gtk_css_area_value_try_parse (GtkCssParser *parser)
{
  guint i;

  g_return_val_if_fail (parser != NULL, NULL);

  for (i = 0; i < G_N_ELEMENTS (area_values); i++)
    {
      if (_gtk_css_parser_try (parser, area_values[i].name, TRUE))
        return _gtk_css_value_ref (&area_values[i]);
    }

  return NULL;
}

GtkCssArea
_gtk_css_area_value_get (const GtkCssValue *value)
{
  g_return_val_if_fail (value->class == &GTK_CSS_VALUE_AREA, GTK_CSS_AREA_BORDER_BOX);

  return value->value;
}

/* GtkCssDirection */

static const GtkCssValueClass GTK_CSS_VALUE_DIRECTION = {
  gtk_css_value_enum_free,
  gtk_css_value_enum_compute,
  gtk_css_value_enum_equal,
  gtk_css_value_enum_transition,
  gtk_css_value_enum_print
};

static GtkCssValue direction_values[] = {
  { &GTK_CSS_VALUE_DIRECTION, 1, GTK_CSS_DIRECTION_NORMAL, "normal" },
  { &GTK_CSS_VALUE_DIRECTION, 1, GTK_CSS_DIRECTION_REVERSE, "reverse" },
  { &GTK_CSS_VALUE_DIRECTION, 1, GTK_CSS_DIRECTION_ALTERNATE, "alternate" },
  { &GTK_CSS_VALUE_DIRECTION, 1, GTK_CSS_DIRECTION_ALTERNATE_REVERSE, "alternate-reverse" }
};

GtkCssValue *
_gtk_css_direction_value_new (GtkCssDirection direction)
{
  guint i;

  for (i = 0; i < G_N_ELEMENTS (direction_values); i++)
    {
      if (direction_values[i].value == direction)
        return _gtk_css_value_ref (&direction_values[i]);
    }

  g_return_val_if_reached (NULL);
}

GtkCssValue *
_gtk_css_direction_value_try_parse (GtkCssParser *parser)
{
  guint i;

  g_return_val_if_fail (parser != NULL, NULL);

  for (i = 0; i < G_N_ELEMENTS (direction_values); i++)
    {
      if (_gtk_css_parser_try (parser, direction_values[i].name, TRUE))
        return _gtk_css_value_ref (&direction_values[i]);
    }

  return NULL;
}

GtkCssDirection
_gtk_css_direction_value_get (const GtkCssValue *value)
{
  g_return_val_if_fail (value->class == &GTK_CSS_VALUE_DIRECTION, GTK_CSS_DIRECTION_NORMAL);

  return value->value;
}

/* GtkCssPlayState */

static const GtkCssValueClass GTK_CSS_VALUE_PLAY_STATE = {
  gtk_css_value_enum_free,
  gtk_css_value_enum_compute,
  gtk_css_value_enum_equal,
  gtk_css_value_enum_transition,
  gtk_css_value_enum_print
};

static GtkCssValue play_state_values[] = {
  { &GTK_CSS_VALUE_PLAY_STATE, 1, GTK_CSS_PLAY_STATE_RUNNING, "running" },
  { &GTK_CSS_VALUE_PLAY_STATE, 1, GTK_CSS_PLAY_STATE_PAUSED, "paused" }
};

GtkCssValue *
_gtk_css_play_state_value_new (GtkCssPlayState play_state)
{
  guint i;

  for (i = 0; i < G_N_ELEMENTS (play_state_values); i++)
    {
      if (play_state_values[i].value == play_state)
        return _gtk_css_value_ref (&play_state_values[i]);
    }

  g_return_val_if_reached (NULL);
}

GtkCssValue *
_gtk_css_play_state_value_try_parse (GtkCssParser *parser)
{
  guint i;

  g_return_val_if_fail (parser != NULL, NULL);

  for (i = 0; i < G_N_ELEMENTS (play_state_values); i++)
    {
      if (_gtk_css_parser_try (parser, play_state_values[i].name, TRUE))
        return _gtk_css_value_ref (&play_state_values[i]);
    }

  return NULL;
}

GtkCssPlayState
_gtk_css_play_state_value_get (const GtkCssValue *value)
{
  g_return_val_if_fail (value->class == &GTK_CSS_VALUE_PLAY_STATE, GTK_CSS_PLAY_STATE_RUNNING);

  return value->value;
}

/* GtkCssFillMode */

static const GtkCssValueClass GTK_CSS_VALUE_FILL_MODE = {
  gtk_css_value_enum_free,
  gtk_css_value_enum_compute,
  gtk_css_value_enum_equal,
  gtk_css_value_enum_transition,
  gtk_css_value_enum_print
};

static GtkCssValue fill_mode_values[] = {
  { &GTK_CSS_VALUE_FILL_MODE, 1, GTK_CSS_FILL_NONE, "none" },
  { &GTK_CSS_VALUE_FILL_MODE, 1, GTK_CSS_FILL_FORWARDS, "forwards" },
  { &GTK_CSS_VALUE_FILL_MODE, 1, GTK_CSS_FILL_BACKWARDS, "backwards" },
  { &GTK_CSS_VALUE_FILL_MODE, 1, GTK_CSS_FILL_BOTH, "both" }
};

GtkCssValue *
_gtk_css_fill_mode_value_new (GtkCssFillMode fill_mode)
{
  guint i;

  for (i = 0; i < G_N_ELEMENTS (fill_mode_values); i++)
    {
      if (fill_mode_values[i].value == fill_mode)
        return _gtk_css_value_ref (&fill_mode_values[i]);
    }

  g_return_val_if_reached (NULL);
}

GtkCssValue *
_gtk_css_fill_mode_value_try_parse (GtkCssParser *parser)
{
  guint i;

  g_return_val_if_fail (parser != NULL, NULL);

  for (i = 0; i < G_N_ELEMENTS (fill_mode_values); i++)
    {
      if (_gtk_css_parser_try (parser, fill_mode_values[i].name, TRUE))
        return _gtk_css_value_ref (&fill_mode_values[i]);
    }

  return NULL;
}

GtkCssFillMode
_gtk_css_fill_mode_value_get (const GtkCssValue *value)
{
  g_return_val_if_fail (value->class == &GTK_CSS_VALUE_FILL_MODE, GTK_CSS_FILL_NONE);

  return value->value;
}

