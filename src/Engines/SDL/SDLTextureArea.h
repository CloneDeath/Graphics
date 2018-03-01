#pragma once

#include "../../TextureArea.h"
#include "SDLRenderer.h"
#include "SDLTexture.h"

namespace Graphics::Engines::SDL {
	class SDLTextureArea : public TextureArea {
	public:
		inline SDLTextureArea(SDLRenderer* renderer, SDLTexture* texture, Rectangle area)
				: renderer(renderer), texture(texture), area(area) {}

		void render(Position position) override;

		SDLRenderer* renderer;
		SDLTexture* texture;
		Rectangle area;
	};
}