#pragma once

#include "Size.h"
#include "Position.h"
#include "TextureArea.h"
#include "Rectangle.h"

namespace Graphics {
	class Texture {
	public:
		virtual void render(Position position) = 0;
		virtual TextureArea* getArea(Rectangle area) = 0;
		virtual Size getSize() = 0;
	};
}