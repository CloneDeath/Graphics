#pragma once

#include "Position.h"

namespace Graphics {
	class TextureArea{
	public:
		virtual void render(Position position) = 0;
	};
}