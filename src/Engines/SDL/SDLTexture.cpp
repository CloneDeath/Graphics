#include "SDLTexture.h"
#include "SDLTextureArea.h"

using namespace Graphics::Engines::SDL;

SDLTexture::~SDLTexture() {
	SDL_DestroyTexture(handle);
}

void SDLTexture::render(Graphics::Position position) {
	auto rect = SDL_Rect();
	rect.x = position.x;
	rect.y = position.y;
	auto size = getSize();
	rect.w = size.width;
	rect.h = size.height;
	SDL_RenderCopy(renderer->handle, handle, nullptr, &rect);
}

Graphics::TextureArea *SDLTexture::getArea(Rectangle area) {
	return new SDLTextureArea(renderer, this, area);
}

Graphics::Size SDLTexture::getSize() {
	int width, height;
	SDL_QueryTexture(handle, nullptr, nullptr, &width, &height);
	return Size(width, height);
}
