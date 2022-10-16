#include "TimedTextCWrapper.h"
#include "SubtitleTypes.h"


extern "C"
{
	CLengthExpression* create_length_expression(double value, CLengthUnit unit, COrientation orientation) {
		auto* len_expr =  new timedText::LengthExpression(value, static_cast<timedText::LengthUnit>(unit), static_cast<timedText::Orientation>(orientation));
		return reinterpret_cast<CLengthExpression*>(len_expr);
	}

	CLengthExpression* create_length_expression_from_value(double value) {
		auto* len_expr = new timedText::LengthExpression(value, timedText::LengthUnit::percentage, timedText::Orientation::Horizontal);
		return reinterpret_cast<CLengthExpression*>(len_expr);
	}

	void free_length_expression(CLengthExpression* len_expr) {
		timedText::LengthExpression* original_len_expr = reinterpret_cast<timedText::LengthExpression*>(len_expr);
		delete original_len_expr;
	}

	int32_t to_pixel(CLengthExpression* len_expr, int32_t width, int32_t height) {
		timedText::LengthExpression* original_len_expr = reinterpret_cast<timedText::LengthExpression*>(len_expr);
		return original_len_expr->toPixel(timedText::Point<timedText::Px>{ width, height });
	}

	bool is_default_c_length_expression(CLengthExpression* c_len_expr) {
		auto* default_len_expr = reinterpret_cast<timedText::LengthExpression*>(create_length_expression_from_value(0.0));
		auto* len_expr = reinterpret_cast<timedText::LengthExpression*>(c_len_expr);
		return (&default_len_expr == &len_expr);
	}

	/////////////////////////////////////////////////////////////////////////////////
	void create_text_outline_default(CTextOutline* text_outline) {		
		text_outline->thickness = create_length_expression_from_value(0.0),
		text_outline->blurRadius = create_length_expression_from_value(0.0);
		text_outline->colorARGB = 0;
	}

	bool is_text_outline_default(CTextOutline c_text_outline) {
		return is_default_c_length_expression(c_text_outline.blurRadius) &&
			is_default_c_length_expression(c_text_outline.thickness) &&
			c_text_outline.colorARGB == 0;
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

	void free_text_outline(CTextOutline c_text_outline) {
		free_length_expression(c_text_outline.blurRadius);
		free_length_expression(c_text_outline.thickness);
	}

}