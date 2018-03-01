#pragma once

#include "Size.h"

namespace Graphics {
	class Position {
	public:
		inline Position(int x, int y) : x(x), y(y) {};
		inline Position(Graphics::Size other) : x(other.width), y(other.height) {};

		int x;
		int y;

		inline Position operator*(Position other) { return Position(x * other.x, y * other.y); }
	};
}

