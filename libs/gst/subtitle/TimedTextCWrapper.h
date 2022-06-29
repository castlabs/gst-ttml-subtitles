#pragma once

#ifndef __cplusplus
#include <stdbool.h>
#endif

#include <stdint.h>
typedef struct CLengthExpression CLengthExpression;
typedef struct CLengthExpression CFontSize; //horizontal font size
typedef struct TextDecoration CTextDecoration;
typedef struct Point CPoint;
typedef struct TextOutline CTextOutline;
typedef struct Rect CRect;

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { pixel, em, cell, percentage } CLengthUnit;
typedef enum { Horizontal, Vertical } COrientation;

CLengthExpression* create_length_expression(double, CLengthUnit, COrientation);
void free_length_expression(CLengthExpression*);
uint32_t to_pixel(CLengthExpression*, uint32_t, uint32_t);

//-------------------------------------------------------------------

struct TextDecoration {
	bool isUnderline;
	bool isLineThrough;
	bool isOverline;
};

struct Point {
	CLengthExpression* x;
	CLengthExpression* y;
};

struct Rect {
	CLengthExpression* left;
	CLengthExpression* top;
	CLengthExpression* right;
	CLengthExpression* bottom;
};

struct TextOutline {
	CLengthExpression* thickness;
	CLengthExpression* blurRadius;
	uint32_t colorARGB;
};

#ifdef __cplusplus
}
#endif
