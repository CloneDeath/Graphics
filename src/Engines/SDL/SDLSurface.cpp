#include "SDLSurface.h"

using namespace Graphics::Engines::SDL;

SDLSurface::~SDLSurface() {
	SDL_FreeSurface(handle);
}
