#include "SDLTextureArea.h"
#include "SDLRectangle.h"

using namespace Graphics::Engines::SDL;

void SDLTextureArea::render(Graphics::Position position) {
	auto src = getSdlRect(this->area);
	auto dst = SDL_Rect();
	dst.x = position.x;
	dst.y = position.y;
	auto size = texture->getSize();
	dst.w = size.width;
	dst.h = size.height;
	SDL_RenderCopy(renderer->handle, texture->handle, &src, &dst);
}
