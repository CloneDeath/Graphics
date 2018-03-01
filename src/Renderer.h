#pragma once

#include "Texture.h"
#include "Font.h"

namespace Graphics {
	class Renderer {
	public:
		virtual void clear() = 0;
		virtual void present() = 0;
		virtual Texture* createTexture(const std::string &filePath) = 0;
		virtual Texture* createTexture(const Surface* surface) = 0;
		virtual Font* createFont(const std::string &fontPath, int fontSize) = 0;
		virtual void setDrawColor(Color color) = 0;
		virtual void drawRectangle(Rectangle rectangle) = 0;
	};
}