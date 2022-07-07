#ifndef _TEXTURE_H_
#define _TEXTURE_H_


#include <SDL2/SDL.h>
#include "Color.h"
#include "matrix.h"

#define TOP_LEFT_UV       (Vec2){0, 1}
#define TOP_RIGHT_UV      (Vec2){1, 1}
#define BOTTOM_LEFT_UV    (Vec2){0, 0}
#define BOTTOM_RIGHT_UV   (Vec2){1, 0}

class Texture
{
    private:
        unsigned int    width;
        unsigned int    height;
        Color*          texels;
        
        SDL_Surface*    loadSurface(const char* fileName) const;

    public:
        Texture(){}
        Texture(const char* fileName);
        ~Texture();


		inline Color	bind_texture	(Vec2& UV)const
		{
			if (UV.x < 0 || UV.y < 0)
				return Color(255,255,255,255);

			UV.x = (UV.x - floor(UV.x)) * (width  - 1);
			UV.y = (UV.y - floor(UV.y)) * (height - 1);

			return getexels(UV.x,UV.y);
		}

		inline Color    getexels (int i, int j) const
		{
			return (j * width) + i > 0 && (j * width) + i < width * height ? texels[(j * width) + i] : Color(0,0,0,0);
		}
};

#endif
