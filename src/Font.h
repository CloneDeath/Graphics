#pragma once

#include "Surface.h"
#include "Color.h"
#include <string>

namespace Graphics {
	class Font{
	public:
		virtual Surface* renderText(std::string message, Color color) = 0;
	};
}