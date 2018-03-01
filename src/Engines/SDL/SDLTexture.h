#pragma once

#include <SDL_render.h>
#include "../../Texture.h"
#include "SDLRenderer.h"

namespace Graphics::Engines::SDL {
	class SDLTexture : public Texture {
	public:
		inline SDLTexture(SDLRenderer* renderer, SDL_Texture* handle) : renderer(renderer), handle(handle) {}
		~SDLTexture();

		void render(Position position) override;
		TextureArea* getArea(Rectangle area) override;
		Size getSize() override;

		SDLRenderer* renderer;
		SDL_Texture* handle;
	};
}
