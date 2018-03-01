#pragma once

#include <exception>
#include <string>

namespace Graphics::Engines::SDL {
	class SDLException : std::exception {
	public:
		explicit SDLException(std::string function_name);
		const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override;

		std::string function_name;
		std::string sdl_message;
	};
}

