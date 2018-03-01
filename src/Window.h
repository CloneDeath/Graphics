#pragma once

#include <string>
#include <SDL_video.h>
#include "Renderer.h"
#include "Size.h"

namespace Graphics {
	class Window {
	public:
		virtual void setTitle(std::string title) = 0;
		virtual void setSize(Size size) = 0;
		virtual Size getSize() = 0;
		virtual void show() = 0;

		virtual Renderer* createRenderer() = 0;
	};
}