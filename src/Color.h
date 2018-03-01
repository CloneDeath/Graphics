#pragma once

namespace Graphics {
	class Color {
	public:
		inline Color(float red, float green, float blue, float alpha) : red(red), green(green), blue(blue), alpha(alpha){};
		float red;
		float green;
		float blue;
		float alpha;

		const static Color White;
		const static Color Black;
	};
}