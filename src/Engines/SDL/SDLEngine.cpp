#include <SDL_image.h>
#include <SDL_ttf.h>
#include "SDLEngine.h"
#include "SDLException.h"
#include "SDLWindow.h"

using namespace Graphics::Engines::SDL;

SDLEngine::SDLEngine() {
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		throw SDLException("SDL_Init");
	}

	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG){
		SDL_Quit();
		throw SDLException("IMG_Init");
	}

	if (TTF_Init() != 0){
		IMG_Quit();
		SDL_Quit();
		throw SDLException("TTF_Init");
	}
}

SDLEngine::~SDLEngine() {
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

Graphics::Window *SDLEngine::createWindow() {
	auto window = SDL_CreateWindow("", 0, 0, 640, 480, 0);
	if (window == nullptr) throw SDLException("SDL_CreateWindow");
	return new SDLWindow(window);
}
