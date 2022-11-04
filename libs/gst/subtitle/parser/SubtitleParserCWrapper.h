#pragma once

//Gstreamer C wrapper for SubtitleParser.h

#ifndef __cplusplus
#include <stdbool.h>
#endif

#include <glib.h>

#if defined(gstttmlcommon_EXPORTS)
#if defined(WIN32)
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __attribute__ ((visibility ("default")))
#endif
#else
#define DLLEXPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CParser CParser;

DLLEXPORT CParser* create_subs_parser();
DLLEXPORT bool parse_subs(CParser*, char*, bool);
DLLEXPORT GList* get_subtitles(CParser*);
DLLEXPORT void free_subtitles (GList*);
DLLEXPORT void destroy_subs_parser (CParser*);

#ifdef __cplusplus
}
#endif
