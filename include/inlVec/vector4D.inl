#ifndef __VECTOR4D_INL__
#define __VECTOR4D_INL__

#include "vector.hpp"

//==================================================================================================

inline Vec4:: Vec4		(float _x,float _y, float _z, float _w):
	x{_x},
	y{_y},
	z{_z},
	w{_w}
{
}

inline Vec4::  Vec4		(const Vec4& CopyVector):
	x	{CopyVector.x},
	y	{CopyVector.y},
	z	{CopyVector.z},
	w 	{CopyVector.w}
{
}

inline Vec4:: Vec4		(float xyzw):
	x	{xyzw},
	y	{xyzw},
	z	{xyzw},
	w 	{xyzw}
{
}

inline Vec4:: Vec4		(const Vec3& CopyVector, float _w):
	x	{CopyVector.x},
	y	{CopyVector.y},
	z	{CopyVector.z},
	w 	{_w}
{
}

inline Vec4:: Vec4		(const Vec2& CopyVector, float _z, float _w):
	x	{CopyVector.x},
	y	{CopyVector.y},
	z	{_z},
	w 	{_w}
{
}

inline Vec4:: ~Vec4	()
{
}

//==================================================================================================

inline float 	Vec4::		X		()const
{
	return x;
}

inline float 	Vec4::		Y		()const
{
	return y;
}

inline float 	Vec4::		Z		()const
{
	return z;
}

inline float	Vec4::		W		()const
{
	return w;
}

inline float&		Vec4::		X		()
{
	return x;
}

inline float&		Vec4::		Y		()
{
	return y;
}

inline float&		Vec4::		Z		()
{
	return z;
}

inline float&		Vec4::		W		()
{
	return w;
}

//==================================================================================================
inline Vec4&		Vec4::		homogenize		()
{
	if (w == 0)
		return *this;

	return *this /= w;
}

inline float		Vec4::		dot_product		(const Vec4& vect)const
{
	return (x * vect.x) + (y * vect.y) + (z * vect.z);
}

inline float		Vec4::		length			()const
{
	return sqrtf(powf(x , 2)+ powf(y , 2) + powf(z , 2));
}

inline float		Vec4::		magnitude		()
{
	homogenize();
	return sqrtf(powf(x , 2)+ powf(y , 2) + powf(z , 2));
}

inline Vec4 	Vec4::		cross_product	(const Vec4& vect)const
{
	return Vec4(  (y * vect.z) - (z * vect.y), 
					  (z * vect.x) - (vect.z * x),
					  (x * vect.y) - (y * vect.x));
}

inline float		Vec4::		dist			(const Vec4& vect)const
{
	return sqrtf( powf( (vect.x - x), 2) + powf( (vect.y - y), 2)  + powf( (vect.z - z), 2));
}

//==================================================================================================

inline Vec4	Vec4::	add					(const Vec4& vector)const
{
	return Vec4(x + vector.x, y + vector.y , z + vector.z, w + vector.w);
}

inline Vec4	Vec4::	substract			(const Vec4& vector)const
{
	return Vec4(x - vector.x, y - vector.y , z - vector.z, w - vector.w);
}

inline Vec4	Vec4::	scale				(float	scale)const
{
	return Vec4(x * scale, y * scale, z * scale, w * scale);
}

inline Vec4	Vec4::	divide_by			(float	scale)const
{
	return scale == 0 ? Vec4( x / scale, y / scale, z / scale, w / scale) : Vec4(0.0f,0.0f,0.0f,0.0f);
}

inline Vec4	Vec4::	divide				(float	scale)const
{
	return x == 0 || y == 0 || z == 0 || w == 0 ? Vec4(scale / x ,scale / y , scale / z, scale / w) : Vec4(0.0f,0.0f,0.0f,0.0f) ;
}


inline Vec4	Vec4::	normalize			()const
{
	float _length = length();
	return _length == 0 ? Vec4(x / _length, y / _length, z / _length, w / _length) : Vec4(0.0f,0.0f,0.0f,0.0f) ;
}

inline Vec4	Vec4::	enlarge				()const
{
	float _length = length();
	float _x = x;
	float _y = y;
	float _z = z;
	return Vec4((_x *= ((_length + 1) / _length)),(_y *= ((_length + 1) / _length)) , (_z *= ((_length + 1) / _length)));
}

inline Vec4	Vec4::	shrink				()const
{
	float _length = length();
	float _x = x;
	float _y = y;
	float _z = z;
	return Vec4((_x *= ((_length - 1) / _length)),(_y *= ((_length - 1) / _length)) , (_z *= ((_length - 1) / _length)));
}

inline Vec4	Vec4::	negate				()const
{
	return Vec4(-x,-y,-z,-w);
}

//==================================================================================================

inline Vec4&			Vec4::	add				(const Vec4& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	w += vector.w;
	return *this;
}

inline Vec4&			Vec4::	substract		(const Vec4& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	w -= vector.w;
	return *this;
}

inline Vec4&			Vec4::	scale			(float scale)
{
	x *= scale;
	y *= scale;
	z *= scale;
	w *= scale;
	return *this;
}

inline Vec4&			Vec4::	divide_by		(float scale)
{
	x /= scale;
	y /= scale;
	z /= scale;
	w /= scale;
	return *this;
}

inline Vec4&			Vec4::	divide			(float scale)
{
	x = scale / x;
	y = scale / y;
	z = scale / z;
	w = scale / w;
	return *this;
}

inline Vec4&		Vec4::	normalize			()
{
	float _length = length();
	if (_length == 0)
		return *this;
	x /= _length;
	y /= _length;
	z /= _length;
	w /= _length;
	return *this;
}

inline Vec4&		Vec4::	enlarge				()
{
	float _length = length();
	if (_length == 0)
		return *this;
	x *= (_length + 1) / _length; 
	y *= (_length + 1) / _length;
	z *= (_length + 1) / _length;
	return *this;
}

inline Vec4&		Vec4::	shrink				()
{
	float __length = length();
	if (__length == 0)
		return *this;
	x *= (__length - 1) / __length; 
	y *= (__length - 1) / __length;
	z *=  (__length - 1) / __length;
	return *this;
}

inline Vec4&		Vec4::	negate				()
{
	x = -x;
	y = -y;
	z = -z;
	w = -w;
	return *this;
}

//==================================================================================================

inline void 		Vec4::		operator=		(float v)
{
	*this = v;
}

inline std::string			operator+		(std::string str,const Vec4& vector)
{
	return str + vector.into_string();
}

inline void				operator+=		(std::string& str,const Vec4& vector)
{
	str = str + vector.into_string();
}

inline std::string	Vec4::	into_string		()const
{
	std::string str = "x:" + std::to_string(x) + ", y:" + std::to_string(y) + ", z :" + std::to_string(z) + ", w:" + std::to_string(w);
  	return str;	
}

//==================================================================================================

inline float& 	Vec4::		operator[]		(int i)
{
	if (i == 0 || i == 'x' || i == 'X')
		return x;
	else if (i == 1 || i == 'y' || i == 'Y')
		return y;
	else if (i == 2 || i == 'z' || i == 'Z')
		return z;
	else if (i == 3 || i == 'w' || i == 'W')
		return w;

	float f 	= 0.0f;
	float& t	= f;
	return t;
}

inline float&		Vec4::		operator[]		(std::string str)
{
	if (str == "x" || str == "X")
		return x;
	else if (str == "y" || str == "Y")
		return y;
	else if (str == "z" || str == "Z")
		return z;
	else if (str == "w" || str == "W")
		return w;

	float f 	= 0.0f;
	float& t	= f;
	return t;

}

inline float 	Vec4::		operator[]		(int i)const
{
	if (i == 0 || i == 'x' || i == 'X')
		return x;
	else if (i == 1 || i == 'y' || i == 'Y')
		return y;
	else if (i == 2 || i == 'z' || i == 'Z')
		return z;
	else if (i == 3 || i == 'w' || i == 'W')
		return w;

	return 0.0f;
}

inline float	Vec4::		operator[]		(std::string str)const
{
	if (str == "x" || str == "X")
		return x;
	else if (str == "y" || str == "Y")
		return y;
	else if (str == "z" || str == "Z")
		return z;
	else if (str == "w" || str == "W")
		return w;

	return 0.0f;
}

//==================================================================================================

inline std::ostream&	operator<<		(std::ostream& print, Vec4& vector)
{
	print << vector.x << "," << vector.y << "," << vector.z << "," << vector.w;
	return print;
}

inline std::istream&	operator>>		(std::istream& in, Vec4& vector)
{
	in >> vector['x'];
	char c;
	in >> c;
	if ( c != ',')
	{
		vector = Vec4(0.0f,0.0f,0.0f,0.0f);
		return in;
	}
	in >> vector['y'];
	return in;	
}

//==================================================================================================

inline bool	Vec4::		operator==		(const Vec4& vector)const
{
	if (x == vector.x && y == vector.y && z == vector.z && w == vector.w)
		return true;
	return false;
}

inline bool	Vec4::		operator!=		(const Vec4& vector)const
{
	if (x != vector.x || y != vector.y || z != vector.z || w != vector.w)
		return true;
	return false;
}

inline bool	Vec4::		operator<=		(const Vec4& vector)const
{
	if (length() <= vector.length())
		return true;
	return false;
}

inline bool	Vec4::		operator<		(const Vec4& vector)const
{
	if (length() < vector.length())
		return true;
	return false;
}

inline bool	Vec4::		operator>		(const Vec4& vector)const
{
	if (length() > vector.length())
		return true;
	return false;
}

inline bool	Vec4::		operator>=		(const Vec4& vector)const
{
	if (length() >= vector.length())
		return true;
	return false;
}

//==================================================================================================

inline Vec4 	Vec4::		operator+		(const Vec4& vector)const
{
	return add(vector);
}

inline Vec4&		Vec4::		operator+=		(const Vec4& vector)
{
	return add(vector);
}

inline Vec4 	Vec4::		operator-		(const Vec4& vector)const
{
	return substract(vector);
}

inline Vec4&		Vec4::		operator-=		(const Vec4& vector)
{
	return substract(vector);
}

inline Vec4	Vec4::		operator-		()const
{
	return negate();
}

inline Vec4&		Vec4::		operator-		()
{
	return negate();
}

inline Vec4	Vec4::	operator*		(float _scale)const
{
	return scale(_scale);
}

inline Vec4		operator*		(float scale,const Vec4& vector)
{
	return vector.scale(scale);
}

inline Vec4	Vec4::	operator/		(float scale)const
{
	return divide_by(scale);
}

inline Vec4		operator/		(float scale,const Vec4& vector)
{
	return vector.divide(scale);
}

inline Vec4&		Vec4::	operator*=		(float _scale)
{
	return scale(_scale);
}
inline Vec4&		Vec4::	operator/=		(float scale)
{
	return divide_by(scale);
}
inline Vec4	Vec4:: 	operator++		()const
{
	return enlarge();
}

inline Vec4&		Vec4:: 	operator++		()
{
	return enlarge();
}

inline Vec4	Vec4:: 	operator++		(int)const
{
	return enlarge();
}

inline Vec4&		Vec4:: 	operator++		(int)
{
	return enlarge();
}

inline Vec4	Vec4:: 	operator--		()const
{
	return shrink();
}

inline Vec4&		Vec4:: 	operator--		()
{
	return shrink();
}

inline Vec4	Vec4:: 	operator--		(int)const
{
	return shrink();
}

inline Vec4&		Vec4:: 	operator--		(int)
{
	return shrink();
}

inline float		Vec4::	operator,		(const Vec4& vector)const
{
	return dot_product(vector);
}

inline Vec4	Vec4::	operator^		(const Vec4& vector)const
{
	return cross_product(vector);
}

#endif //__VECTOR4D_INL__
