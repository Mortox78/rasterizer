#ifndef __COLOR_INL__
#define __COLOR_INL__

#include "Color.h"

inline Color::Color()
{
    r = 0;
    g = 0;
    b = 0;
    a = 255;
}


inline Color::Color(const Color& copyColor):
    r {copyColor.r},
    g {copyColor.g},
    b {copyColor.b},
    a {copyColor.a}
    {}



inline Color::Color(const unsigned char r, const unsigned char g, const unsigned char b, const unsigned char a)
{
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = a;
}

inline Color 		Color::operator*	(const float& scalar)const
{
	return {(unsigned char)(r * scalar), (unsigned char)(g * scalar), (unsigned char)(b * scalar), (unsigned char)(a * scalar)};
}

inline Color		Color::operator+	(const Color& addColor)const
{
	return {(unsigned char)(r + addColor.r), (unsigned char)(g + addColor.g), (unsigned char)(b + addColor.b), (unsigned char)(a + addColor.a)};
}

inline Color 		Color::operator/	(const float& scalar)const
{
	return {(unsigned char)(r / scalar), (unsigned char)(g / scalar), (unsigned char)(b / scalar), (unsigned char)(a / scalar)};
}

inline Color&		Color::operator=	(const Color& copyColor)
{
	r = copyColor.r;
	g = copyColor.g;
	b = copyColor.b;
	a = copyColor.a;

	return *this;
}

#endif //__COLOR_INL__
