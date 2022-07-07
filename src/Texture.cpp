#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <assert.h>
#include "Texture.hpp"



Texture::Texture(const char* fileName)
{
    // Extract an SDL_Surface from the image and gather informations
    SDL_Surface* loadedImage       = loadSurface(fileName);
    Color*       loadedImagePixels = (Color*)loadedImage->pixels; 

    width  = loadedImage->w;
    height = loadedImage->h;
    texels = new Color[width * height];

    // copy the pixels of the image in our texture
    for (unsigned int i = 0; i < width * height; ++i)
    {
        texels[i] = loadedImagePixels[i];
    }

    SDL_FreeSurface(loadedImage);
}

Texture::~Texture()
{
    delete[] texels;
}

SDL_Surface* Texture::loadSurface(const char* fileName) const
{
    SDL_Surface* loadedSurface = IMG_Load( fileName );
    assert(loadedSurface->format->BytesPerPixel == sizeof(Color));
    return loadedSurface;
}
