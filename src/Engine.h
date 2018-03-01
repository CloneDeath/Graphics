#pragma once

#include "Window.h"

namespace Graphics {
	class Engine {
		virtual Window* createWindow() = 0;
	};
}

