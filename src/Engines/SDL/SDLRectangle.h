#pragma once

#include <SDL_rect.h>
#include "../../Rectangle.h"

namespace Graphics::Engines::SDL{
	inline SDL_Rect getSdlRect(Graphics::Rectangle area){
		auto rect = SDL_Rect();
		rect.x = area.x;
		rect.y = area.y;
		rect.w = area.width;
		rect.h = area.height;
		return rect;
	}
}