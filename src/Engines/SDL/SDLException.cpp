#include <SDL_quit.h>
#include "SDLException.h"

using namespace Graphics::Engines::SDL;

SDLException::SDLException(std::string function_name) {
	function_name = function_name;
	sdl_message = SDL_GetError();
}

const char *SDLException::what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT {
	return (function_name + " " + sdl_message).c_str();
}
