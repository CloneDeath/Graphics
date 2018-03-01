#include <SDL_image.h>
#include <SDL_ttf.h>
#include "SDLRenderer.h"
#include "SDLException.h"
#include "SDLTexture.h"
#include "SDLFont.h"
#include "SDLSurface.h"
#include "SDLRectangle.h"
#include "SDLColor.h"

using namespace Graphics::Engines::SDL;

SDLRenderer::SDLRenderer(SDL_Renderer *handle) {
	this->handle = handle;
}

SDLRenderer::~SDLRenderer() {
	SDL_DestroyRenderer(handle);
}

Graphics::Texture *SDLRenderer::createTexture(const std::string &filePath) {
	auto texture = IMG_LoadTexture(handle, filePath.c_str());
	if (texture == nullptr) throw SDLException("IMG_LoadTexture");
	return new SDLTexture(this, texture);
}

Graphics::Font *SDLRenderer::createFont(const std::string &fontPath, int fontSize) {
	auto font = TTF_OpenFont(fontPath.c_str(), fontSize);
	if (font == nullptr) throw SDLException("TTF_OpenFont");
	return new SDLFont(font);
}

Graphics::Texture *SDLRenderer::createTexture(const Graphics::Surface *surface) {
	auto surf = (SDLSurface*)surface;
	auto texture = SDL_CreateTextureFromSurface(handle, surf->handle);
	if (texture == nullptr) throw SDLException("SDL_CreateTextureFromSurface");
	return new SDLTexture(this, texture);
}

void SDLRenderer::clear() {
	SDL_RenderClear(handle);
}

void SDLRenderer::present() {
	SDL_RenderPresent(handle);
}

void SDLRenderer::setDrawColor(Graphics::Color color) {
	auto c = getSdlColor(color);
	SDL_SetRenderDrawColor(handle, c.r, c.g, c.b, c.a);
}

void SDLRenderer::drawRectangle(Graphics::Rectangle rectangle) {
	auto rect = getSdlRect(rectangle);
	SDL_RenderDrawRect(handle, &rect);
}
