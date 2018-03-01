#pragma once

#include "../../Window.h"

namespace Graphics::Engines::SDL {
	class SDLWindow : public Window {
	public:
		explicit SDLWindow(SDL_Window* handle);
		~SDLWindow();
		void setTitle(std::string title) override;
		void setSize(Size size) override;
		Size getSize() override;
		void show() override;
		Renderer* createRenderer() override;

		SDL_Window* handle;
	};
}

