#ifndef _FRAME_BUFFER_H_
#define _FRAME_BUFFER_H_

#define SCREEN_WIDTH  1024
#define SCREEN_HEIGHT 728

#include "Color.h"
#include "Vertex.h"
#include <vector>
#include <float.h>

#include <SDL2/SDL.h>

class FrameBuffer
{
    private:
        unsigned int        width;
        unsigned int        height;
        Color*              pixels;
        SDL_Texture*        sdl_texture;
        SDL_Rect            rect_FrameBuffer;
        

    public:
		Matrix4<float> 	    view_port;
        float*              z_buffer;

        FrameBuffer(SDL_Renderer* renderer,const unsigned int& width, const unsigned int& height);
        ~FrameBuffer();

		Matrix4<float>	create_ViewPort();
        
		        
		void            pixels_clear();
        void            display(SDL_Renderer* renderer);


        inline unsigned int    	getWidth		()const{return width;}
        inline unsigned int    	getHeight		()const{return height;}
        inline Color			getPixel		(unsigned int x, unsigned int y)const{return pixels[(y * width) + x];}
		inline void             SetPixelColor	(unsigned int x, unsigned int y, const Color& c){pixels[(y * width) + x] = c;}


};

inline void FrameBuffer::pixels_clear  ()
{
    for (unsigned int i = 0; i < width * height; ++i)
	{
    	z_buffer[i]	= FLT_MAX;
	}

	memset(pixels,0,width*height*sizeof(Color));
}




#endif
