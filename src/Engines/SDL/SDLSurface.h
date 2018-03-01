#pragma once

#include <SDL_surface.h>
#include "../../Surface.h"

namespace Graphics::Engines::SDL {
	class SDLSurface : public Surface {
	public:
		inline explicit SDLSurface(SDL_Surface* handle) : handle(handle) {};
		~SDLSurface();
		SDL_Surface* handle;
	};
}

