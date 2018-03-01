#pragma once

#include <SDL_ttf.h>
#include <string>
#include "../../Font.h"

namespace Graphics::Engines::SDL {
	class SDLFont : public Font {
	public:
		inline explicit SDLFont(TTF_Font* handle) : handle(handle) {};
		~SDLFont();

		Surface* renderText(std::string message, Color color) override;

		TTF_Font* handle;
	};
}
