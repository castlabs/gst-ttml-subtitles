#include "TimedTextCWrapper.h"
#include "SubtitleTypes.h"


extern "C"
{
	CLengthExpression* create_length_expression(double value, CLengthUnit unit, COrientation orientation) {
		auto* len_expr =  new timedText::LengthExpression(value, static_cast<timedText::LengthUnit>(unit), static_cast<timedText::Orientation>(orientation));
		return reinterpret_cast<CLengthExpression*>(len_expr);
	}

	void free_length_expression(CLengthExpression* len_expr) {
		timedText::LengthExpression* original_len_expr = reinterpret_cast<timedText::LengthExpression*>(len_expr);
		delete original_len_expr;
	}

	uint32_t to_pixel(CLengthExpression* len_expr, uint32_t width, uint32_t height) {
		timedText::LengthExpression* original_len_expr = reinterpret_cast<timedText::LengthExpression*>(len_expr);
		return original_len_expr->toPixel(timedText::Point<uint32_t>{width, height });
	}
}