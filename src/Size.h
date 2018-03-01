#pragma once

namespace Graphics {
	struct Size {
	public:
		inline Size(int width, int height)
				: width(width),
				  height(height) {};

		int width;
		int height;

		inline Size operator /(int scale) { return Size(width/scale, height/scale); }
		inline Size operator -(Size other) { return Size(width - other.width, height - other.height); }
	};
}