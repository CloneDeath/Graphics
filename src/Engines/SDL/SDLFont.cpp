#include "SDLFont.h"
#include "SDLSurface.h"
#include "SDLException.h"
#include "SDLColor.h"

using namespace Graphics::Engines::SDL;

SDLFont::~SDLFont() {
	TTF_CloseFont(handle);
}

Graphics::Surface *SDLFont::renderText(std::string message, Graphics::Color color) {
	auto surf = TTF_RenderText_Blended(handle, message.c_str(), getSdlColor(color));
	if (surf == nullptr) throw SDLException("TTF_RenderText_Blended");
	return new SDLSurface(surf);
}
