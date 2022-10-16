#pragma once

#ifndef __cplusplus
#include <stdbool.h>
#endif

#include <stdint.h>

#if defined(gstttmlcommon_EXPORTS)
#if defined(WIN32)
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __attribute__ ((visibility ("default")))
#endif
#else
#define DLLEXPORT
#endif

typedef struct CLengthExpression CLengthExpression;
typedef struct CLengthExpression CFontSize; //horizontal font size
typedef struct TextDecoration CTextDecoration;
typedef struct PointLen CPointLen;
typedef struct _TextOutline CTextOutline;
typedef struct RectLen CPaddingLen;

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { pixel, em, cell, percentage } CLengthUnit;
typedef enum { Horizontal, Vertical } COrientation;

//CLengthExpression interface
DLLEXPORT CLengthExpression* create_length_expression(double, CLengthUnit, COrientation);
DLLEXPORT CLengthExpression* create_length_expression_from_value(double);
DLLEXPORT void free_length_expression(CLengthExpression*);
DLLEXPORT int32_t to_pixel(CLengthExpression*, int32_t, int32_t);

//-------------------------------------------------------------------
//TextOutline interface
DLLEXPORT void create_text_outline_default(CTextOutline*);
DLLEXPORT bool is_text_outline_default(CTextOutline);
DLLEXPORT bool is_text_outline_equal(CTextOutline, CTextOutline);
DLLEXPORT void free_text_outline(CTextOutline);

//-------------------------------------------------------------------
struct TextDecoration {
	bool isUnderline;
	bool isLineThrough;
	bool isOverline;
};

struct PointLen {
	CLengthExpression* x;
	CLengthExpression* y;
};

struct RectLen {
	CLengthExpression* left;
	CLengthExpression* top;
	CLengthExpression* right;
	CLengthExpression* bottom;
};

struct _TextOutline {
	CLengthExpression* thickness;
	CLengthExpression* blurRadius;
	uint32_t colorARGB;
};

#ifdef __cplusplus
}
#endif
