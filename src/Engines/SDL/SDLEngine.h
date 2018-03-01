#pragma once

#include <SDL.h>
#include "../../Engine.h"

namespace Graphics::Engines::SDL {
	class SDLEngine : Engine {
	public:
		SDLEngine();
		~SDLEngine();

		Window* createWindow() override;
	};
}
