#pragma once

#include <stdint.h>
typedef struct CLengthExpression CLengthExpression;

#ifdef __cplusplus
extern "C" {
#endif

typedef enum { pixel, em, cell, percentage } CLengthUnit;
typedef enum { Horizontal, Vertical } COrientation;

CLengthExpression* create_length_expression(double, CLengthUnit, COrientation);
void free_length_expression(CLengthExpression*);
uint32_t to_pixel(CLengthExpression*, uint32_t, uint32_t);


#ifdef __cplusplus
}
#endif
