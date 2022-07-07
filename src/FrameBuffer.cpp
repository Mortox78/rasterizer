#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "FrameBuffer.h"
#include "Rasterizer.h"


FrameBuffer::FrameBuffer(SDL_Renderer* renderer,const unsigned int& _width, const unsigned int& _height):
    width               {_width},
    height              {_height},
    pixels              {new Color[width * height]},
    rect_FrameBuffer    {(SDL_Rect){0,0,(int)width,(int)height}},
	view_port		    {create_ViewPort()},
    z_buffer            {new float[width* height]}
{
    sdl_texture = SDL_CreateTexture(renderer,SDL_PIXELFORMAT_RGBA32,SDL_TEXTUREACCESS_STREAMING,width,height);
    pixels_clear();
}

FrameBuffer::~FrameBuffer()
{
    SDL_DestroyTexture(sdl_texture);
    delete[] pixels;
    delete[] z_buffer;
}

Matrix4<float> FrameBuffer::create_ViewPort	()
{
	view_port       = Matrix<float,4,4>::identity();

	view_port[0][0] = width/10;
	view_port[0][3] = width/2;

	view_port[1][1] = (height/10);
	view_port[1][1] *= -1;
	view_port[1][3] = height/2;

	return view_port;
}

void FrameBuffer::display(SDL_Renderer* renderer)
{
    SDL_UpdateTexture(sdl_texture, &rect_FrameBuffer, pixels, width * sizeof(Color));
    SDL_RenderCopy(renderer, sdl_texture, &rect_FrameBuffer, &rect_FrameBuffer);
}
