#pragma once

//Gstreamer C wrapper for SubtitleParser.h

#ifndef __cplusplus
#include <stdbool.h>
#endif

#include <glib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CParser CParser;

CParser* parse_ttml(char*, bool);

GList* get_subtitles(CParser*);

#ifdef __cplusplus
}
#endif
