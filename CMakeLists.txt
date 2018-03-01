cmake_minimum_required(VERSION 3.9)
project(Graphics)

set(CMAKE_CXX_STANDARD 17)

add_library(Graphics
        src/Engines/SDL/SDLColor.h
        src/Engines/SDL/SDLEngine.cpp
        src/Engines/SDL/SDLEngine.h
        src/Engines/SDL/SDLException.cpp
        src/Engines/SDL/SDLException.h
        src/Engines/SDL/SDLFont.cpp
        src/Engines/SDL/SDLFont.h
        src/Engines/SDL/SDLRectangle.h
        src/Engines/SDL/SDLRenderer.cpp
        src/Engines/SDL/SDLRenderer.h
        src/Engines/SDL/SDLSurface.cpp
        src/Engines/SDL/SDLSurface.h
        src/Engines/SDL/SDLTexture.cpp
        src/Engines/SDL/SDLTexture.h
        src/Engines/SDL/SDLTextureArea.cpp
        src/Engines/SDL/SDLTextureArea.h
        src/Engines/SDL/SDLWindow.cpp
        src/Engines/SDL/SDLWindow.h
        src/Color.cpp
        src/Color.h
        src/Engine.h
        src/Font.h
        src/Position.h
        src/Rectangle.h
        src/Renderer.h
        src/Size.h
        src/Surface.h
        src/Texture.h
        src/TextureArea.h
        src/Window.h)