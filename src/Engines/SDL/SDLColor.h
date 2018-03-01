#pragma once

#include <SDL_pixels.h>
#include "../../Color.h"

namespace Graphics::Engines::SDL {
	inline SDL_Color getSdlColor(Graphics::Color color){
		auto c = SDL_Color();
		c.r = (Uint8)(color.red * 255);
		c.g = (Uint8)(color.green * 255);
		c.b = (Uint8)(color.blue * 255);
		c.a = (Uint8)(color.alpha * 255);
		return c;
	}
}