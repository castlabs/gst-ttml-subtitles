#pragma once

#ifndef __cplusplus
#include <stdbool.h>
#endif

#include <stdint.h>

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
CLengthExpression* create_length_expression(double, CLengthUnit, COrientation);
CLengthExpression* create_length_expression_from_value(double);
void free_length_expression(CLengthExpression*);
uint32_t to_pixel(CLengthExpression*, uint32_t, uint32_t);

//-------------------------------------------------------------------
//TextOutline interface
void create_text_outline_default(CTextOutline*);
bool is_text_outline_default(CTextOutline);
bool is_text_outline_equal(CTextOutline, CTextOutline);
void free_text_outline(CTextOutline);

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
