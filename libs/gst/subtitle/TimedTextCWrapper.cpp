#include "TimedTextCWrapper.h"
#include "SubtitleTypes.h"


extern "C"
{
	static timedText::LengthExpression _default_len_expr(0.0, timedText::LengthUnit::percentage, timedText::Orientation::Horizontal);
	#define DEFAULT_LEN_EXPR (CLengthExpression*)(&_default_len_expr)

	CLengthExpression* default_length_expression() {
		return DEFAULT_LEN_EXPR;
	}

	CLengthExpression* create_length_expression(double value, CLengthUnit unit, COrientation orientation) {
		auto* len_expr = new timedText::LengthExpression(value, static_cast<timedText::LengthUnit>(unit), static_cast<timedText::Orientation>(orientation));
		return reinterpret_cast<CLengthExpression*>(len_expr);
	}

	CLengthExpression* create_length_expression_from_value(double value) {
		auto* len_expr = new timedText::LengthExpression(value, timedText::LengthUnit::percentage, timedText::Orientation::Horizontal);
		return reinterpret_cast<CLengthExpression*>(len_expr);
	}

	CLengthExpression* copy_length_expression(CLengthExpression* len_expr) {
		if (DEFAULT_LEN_EXPR == len_expr)
			return len_expr;
		if (!len_expr)
			return NULL;
		auto* len_expr_copy = new timedText::LengthExpression(*reinterpret_cast<timedText::LengthExpression*>(len_expr));
		return reinterpret_cast<CLengthExpression*>(len_expr_copy);
	}

	CLengthExpression* writable_length_expression(CLengthExpression* len_expr) {
		if (DEFAULT_LEN_EXPR != len_expr)
			return len_expr;
		auto* len_expr_copy = new timedText::LengthExpression(*reinterpret_cast<timedText::LengthExpression*>(len_expr));
		return reinterpret_cast<CLengthExpression*>(len_expr_copy);
	}

	void free_length_expression(CLengthExpression* len_expr) {
		if (DEFAULT_LEN_EXPR == len_expr)
			return;
		delete reinterpret_cast<timedText::LengthExpression*>(len_expr);
	}

	int32_t to_pixel(CLengthExpression* len_expr, int32_t width, int32_t height) {
		timedText::LengthExpression* original_len_expr = reinterpret_cast<timedText::LengthExpression*>(len_expr);
		return original_len_expr->toPixel(timedText::Point<timedText::Px>{ width, height });
	}

	static bool is_default_length_expression(CLengthExpression* len_expr) {
		return DEFAULT_LEN_EXPR == len_expr;
	}

	/////////////////////////////////////////////////////////////////////////////////

	void create_text_outline_default(CTextOutline* text_outline) {		
		text_outline->thickness = default_length_expression();
		text_outline->blurRadius = default_length_expression();
		text_outline->colorARGB = 0;
	}

	bool is_text_outline_default(CTextOutline text_outline) {
		return is_default_length_expression(text_outline.blurRadius) &&
			is_default_length_expression(text_outline.thickness) &&
			text_outline.colorARGB == 0;
	}

	bool is_text_outline_equal(CTextOutline lhs, CTextOutline rhs) {
		auto* lhs_blur_radius = reinterpret_cast<timedText::LengthExpression*>(lhs.blurRadius);
		auto* rhs_blur_radius = reinterpret_cast<timedText::LengthExpression*>(rhs.blurRadius);

		auto* lhs_thickness = reinterpret_cast<timedText::LengthExpression*>(lhs.thickness);
		auto* rhs_thickness = reinterpret_cast<timedText::LengthExpression*>(rhs.thickness);

		return lhs_blur_radius == rhs_blur_radius &&
			lhs_thickness == rhs_thickness &&
			lhs.colorARGB == rhs.colorARGB;
	}

	void free_text_outline(CTextOutline text_outline) {
		free_length_expression(text_outline.blurRadius);
		free_length_expression(text_outline.thickness);
	}

}
