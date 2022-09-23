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

CParser* create_subs_parser();
bool parse_subs(CParser*, char*, bool);
GList* get_subtitles(CParser*);
void destroy_subs_parser(CParser*);

#ifdef __cplusplus
}
#endif
