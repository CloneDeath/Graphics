#include "SDLWindow.h"
#include "SDLRenderer.h"
#include "SDLException.h"

using namespace Graphics::Engines::SDL;

SDLWindow::SDLWindow(SDL_Window *handle) {
	this->handle = handle;
}

SDLWindow::~SDLWindow() {
	SDL_DestroyWindow(handle);
}

void SDLWindow::setTitle(std::string title) {
	SDL_SetWindowTitle(handle, title.c_str());
}

void SDLWindow::setSize(Size size) {
	SDL_SetWindowSize(handle, size.width, size.height);
}

Graphics::Size SDLWindow::getSize() {
	int width, height;
	SDL_GetWindowSize(handle, &width, &height);
	return Size(width, height);
}

void SDLWindow::show() {
	SDL_ShowWindow(handle);
}

Graphics::Renderer *SDLWindow::createRenderer() {
	auto renderer = SDL_CreateRenderer(handle, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) throw SDLException("SDL_CreateRenderer");
	return new SDLRenderer(renderer);
}
