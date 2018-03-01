#pragma once

#include "Position.h"

namespace Graphics {
	struct Rectangle {
	public:
		inline Rectangle(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {}
		inline Rectangle(Position position, Size size)
				: x(position.x), y(position.y), width(size.width), height(size.height){}

		int x;
		int y;
		int width;
		int height;
	};
}