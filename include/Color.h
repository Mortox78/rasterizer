#ifndef _COLOR_H_
#define _COLOR_H_

class Color
{
    public:
        inline Color();
        inline Color(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a);
        inline Color(const Color& copyColor);
        inline ~Color(){}

        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;

		inline Color 		operator*	(const float& scalar)const;
		inline Color		operator+	(const Color& addColor)const;
		inline Color		operator/	(const float& scalar)const;
		inline Color&		operator=	(const Color& copyColor);
};

#include "Color.inl"

#endif
