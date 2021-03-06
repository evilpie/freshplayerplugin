/*
 * Copyright © 2013-2014  Rinat Ibragimov
 *
 * This file is part of FreshPlayerPlugin.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef FPP__PPB_FONT_DEV_H
#define FPP__PPB_FONT_DEV_H

#include <ppapi/c/dev/ppb_font_dev.h>


struct PP_Var
ppb_font_dev_get_font_families(PP_Instance instance);

PP_Resource
ppb_font_dev_create(PP_Instance instance, const struct PP_FontDescription_Dev *description);

PP_Bool
ppb_font_dev_is_font(PP_Resource resource);

PP_Bool
ppb_font_dev_describe(PP_Resource font, struct PP_FontDescription_Dev *description,
                      struct PP_FontMetrics_Dev *metrics);

PP_Bool
ppb_font_dev_draw_text_at(PP_Resource font, PP_Resource image_data,
                          const struct PP_TextRun_Dev *text, const struct PP_Point *position,
                          uint32_t color, const struct PP_Rect *clip, PP_Bool image_data_is_opaque);

int32_t
ppb_font_dev_measure_text(PP_Resource font, const struct PP_TextRun_Dev *text);

uint32_t
ppb_font_dev_character_offset_for_pixel(PP_Resource font, const struct PP_TextRun_Dev *text,
                                        int32_t pixel_position);

int32_t
ppb_font_dev_pixel_offset_for_character(PP_Resource font, const struct PP_TextRun_Dev *text,
                                        uint32_t char_offset);

#endif // FPP__PPB_FONT_DEV_H
