cmake_minimum_required(VERSION 3.9)
project(Graphics)

set(CMAKE_CXX_STANDARD 17)

if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
endif(CMAKE_COMPILER_IS_GNUCXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${Graphics_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
include_directories(Graphics ${SDL2_INCLUDE_DIRS})

find_package(SDL2_image REQUIRED)
include_directories(Graphics ${SDL2_image_INCLUDE_DIRS})

find_package(SDL2_ttf REQUIRED)
include_directories(Graphics ${SDL2_ttf_INCLUDE_DIRS})

set(headers
        src/Engines/SDL/SDLColor.h
        src/Engines/SDL/SDLEngine.h
        src/Engines/SDL/SDLException.h
        src/Engines/SDL/SDLFont.h
        src/Engines/SDL/SDLRectangle.h
        src/Engines/SDL/SDLRenderer.h
        src/Engines/SDL/SDLSurface.h
        src/Engines/SDL/SDLTexture.h
        src/Engines/SDL/SDLTextureArea.h
        src/Engines/SDL/SDLWindow.h
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
        src/Window.h
)

set(sources
        src/Engines/SDL/SDLEngine.cpp
        src/Engines/SDL/SDLException.cpp
        src/Engines/SDL/SDLFont.cpp
        src/Engines/SDL/SDLRenderer.cpp
        src/Engines/SDL/SDLSurface.cpp
        src/Engines/SDL/SDLTexture.cpp
        src/Engines/SDL/SDLTextureArea.cpp
        src/Engines/SDL/SDLWindow.cpp
        src/Color.cpp
)

include_directories(include)

add_library(Graphics
        ${sources}
        ${headers}
)

target_link_libraries(Graphics ${SDL2_LIBRARIES})
target_link_libraries(Graphics ${SDL2_IMAGE_LIBRARY})
target_link_libraries(Graphics ${SDL2_TTF_LIBRARY})

install(TARGETS Graphics
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)
install(FILES ${headers} DESTINATION include/Graphics)

macro(Graphics_POSTBUILD_COPY target_)
    add_custom_command(
            TARGET ${target_} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Graphics>
            $<TARGET_FILE_DIR:${target_}>/$<TARGET_FILE_NAME:Graphics>
    )
endmacro(Graphics_POSTBUILD_COPY)