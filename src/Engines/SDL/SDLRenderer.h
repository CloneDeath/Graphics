#pragma once

#include <SDL_render.h>
#include "../../Renderer.h"
#include <string>

namespace Graphics::Engines::SDL {
	class SDLRenderer : public Renderer {
	public:
		explicit SDLRenderer(SDL_Renderer* handle);
		~SDLRenderer();

		void clear() override;
		void present() override;
		Texture* createTexture(const std::string &filePath) override;
		Texture* createTexture(const Surface* surface) override;
		Font* createFont(const std::string &fontPath, int fontSize) override;

		void setDrawColor(Color color) override;

		void drawRectangle(Rectangle rectangle) override;

		SDL_Renderer* handle;
	};
}

