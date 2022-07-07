#ifndef __VECTOR3D_INL__
#define __VECTOR3D_INL__

#include "vector.hpp"

//==================================================================================================

inline Vec3:: Vec3		(float _x,float _y, float _z):
	x{_x},
	y{_y},
	z{_z}
{
}

inline Vec3:: Vec3		(float xyz):
	x {xyz},
	y {xyz},
	z {xyz}
{
}

inline Vec3:: Vec3		(const Vec2& CopyVector, float _z):
	x {CopyVector.x},
	y {CopyVector.y},
	z {_z}
{
}

inline Vec3::	Vec3	(const Vec4& CopyVector):
		x {CopyVector.x},
		y {CopyVector.y},
		z {CopyVector.z}
{
}

inline Vec3::	Vec3	(const Vec3& CopyVector):
	x{CopyVector.x},
	y{CopyVector.y},
	z{CopyVector.z}
{
}

inline Vec3::	~Vec3()
{
}

//==================================================================================================

inline float 	Vec3::		X		()const
{
	return x;
}

inline float 	Vec3::		Y		()const
{
	return y;
}

inline float 	Vec3::		Z		()const
{
	return z;
}

inline float&		Vec3::		X		()
{
	return x;
}

inline float&		Vec3::		Y		()
{
	return y;
}

inline float&		Vec3::		Z		()
{
	return z;
}


//==================================================================================================

inline float		Vec3::		dot_product		(const Vec3& vect)const
{
	return (x * vect.x) + (y * vect.y) + (z * vect.z);
}

inline float		Vec3::		length			()const
{
	return sqrt(pow(x , 2)+ pow(y , 2) + pow(z , 2));
}

inline Vec3 	Vec3::		cross_product	(const Vec3& vect)const
{
	return Vec3(  (y * vect.z) - (z * vect.y), 
					  (z * vect.x) - (vect.z * x),
					  (x * vect.y) - (y * vect.x));
}

inline float		Vec3::		dist			(const Vec3& vect)const
{
	return sqrtf( powf( (vect.x - x), 2) + powf( (vect.y - y), 2)  + powf( (vect.z - z), 2));
}

inline float		Vec3::		get_area		(const Vec3& vect)const
{
	return ( (*this^vect).length() / 2);
}

//==================================================================================================

inline Vec3	Vec3::	add					(const Vec3& vector)const
{
	return Vec3(x + vector.x, y + vector.y , z + vector.z);
}

inline Vec3	Vec3::	substract			(const Vec3& vector)const
{
	return Vec3(x - vector.x, y - vector.y , z - vector.z);
}

inline Vec3	Vec3::	divide_by			(float	_scale)const
{
	return _scale == 0 ? Vec3( x / _scale, y / _scale, z / _scale) : Vec3(0.0f,0.0f,0.0f);
}

inline Vec3	Vec3::	divide				(float	_scale)const
{
	return x == 0 || y == 0 || z == 0 ? Vec3(_scale / x ,_scale / y , _scale / z) : Vec3(0.0f,0.0f,0.0f) ;
}


inline Vec3	Vec3::	normalize			()const
{
	float _length = length();
	return _length == 0 ? Vec3(x / _length, y / _length, z / _length) : Vec3(0.0f,0.0f,0.0f) ;
}

inline Vec3	Vec3::	enlarge				()const
{
	float _length = length();
	float _x = x;
	float _y = y;
	float _z = z;
	return Vec3((_x *= ((_length + 1) / _length)),(_y *= ((_length + 1) / _length)) , (_z *= ((_length + 1) / _length)));
}

inline Vec3	Vec3::	shrink				()const
{
	float _length = length();
	float _x = x;
	float _y = y;
	float _z = z;
	return Vec3((_x *= ((_length - 1) / _length)),(_y *= ((_length - 1) / _length)) , (_z *= ((_length - 1) / _length)));
}

inline Vec3	Vec3::	negate				()const
{
	return Vec3(-x,-y,-z);
}

inline Vec3	Vec3::	rotate_around		(const Vec3& vect, float angle)const
{
	Vec3 composite = (vect , *this) * vect;
	float radian_angle = degrees_to_radian(angle);
	return composite + (cosf(radian_angle) * (*this - composite)) + (sinf(radian_angle) * (vect ^ *this));
}

//==================================================================================================

inline Vec3&			Vec3::	add				(const Vec3& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}

inline Vec3&			Vec3::	substract		(const Vec3& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}

inline Vec3&			Vec3::	scale			(float scale)
{
	x *= scale;
	y *= scale;
	z *= scale;
	return *this;
}

inline Vec3&			Vec3::	divide_by		(float scale)
{
	x /= scale;
	y /= scale;
	z /= scale;
	return *this;
}

inline Vec3&			Vec3::	divide			(float scale)
{
	x = scale / x;
	y = scale / y;
	z = scale / z;
	return *this;
}

inline Vec3&		Vec3::	normalize			()
{
	float _length = length();
	if (_length == 0)
		return *this;
	x /= _length;
	y /= _length;
	z /= _length;
	return *this;
}

inline Vec3&		Vec3::	enlarge				()
{
	float _length = length();
	if (_length == 0)
		return *this;
	x *= (_length + 1) / _length; 
	y *= (_length + 1) / _length;
	z *= (_length + 1) / _length;
	return *this;
}

inline Vec3&		Vec3::	shrink				()
{
	float __length = length();
	if (__length == 0)
		return *this;
	x *= (__length - 1) / __length; 
	y *= (__length - 1) / __length;
	z *=  (__length - 1) / __length;
	return *this;
}

inline Vec3&		Vec3::	negate				()
{
	x = -x;
	y = -y;
	z = -z;
	return *this;
}

inline Vec3&		Vec3::	rotate_around		(const Vec3& vect, float angle)
{
	Vec3 composite = (vect , *this) * vect;
	float radian_angle = degrees_to_radian(angle);
	*this = composite + (cosf(radian_angle) * (*this - composite)) + (sinf(radian_angle) * (vect ^ *this));
	return *this;
}
//==================================================================================================

inline void 		Vec3::	operator=		(float v)
{
	*this = v;
}

inline std::string				operator+		(std::string str,const Vec3& vector)
{
	return str + vector.into_string();
}

inline void						operator+=		(std::string& str,const Vec3& vector)
{
	str = str + vector.into_string();
}

inline std::string	Vec3::	into_string		()const
{
	std::string str = "x:" + std::to_string(x) + ", y:" + std::to_string(y) + ", z:" + std::to_string(z);
  	return str;	
}

//==================================================================================================

inline float& 	Vec3::		operator[]		(int i)
{
	if (i == 0 || i == 'x' || i == 'X')
		return x;
	else if (i == 1 || i == 'y' || i == 'Y')
		return y;
	else if (i == 2 || i == 'z' || i == 'Z')
		return z;

	float f 	= 0.0f;
	float& t	= f;
	return t;
}

inline float&	Vec3::		operator[]		(std::string str)
{
	if (str == "x" || str == "X")
		return x;
	else if (str == "y" || str == "Y")
		return y;
	else if (str == "z" || str == "Z")
		return z;
	float f 	= 0.0f;
	float& t	= f;
	return t;

}

inline float 	Vec3::		operator[]		(int i)const
{
	if (i == 0 || i == 'x' || i == 'X')
		return x;
	else if (i == 1 || i == 'y' || i == 'Y')
		return y;
	else if (i == 2 || i == 'z' || i == 'Z')
		return z;

	return 0.0f;
}

inline float	Vec3::		operator[]		(std::string str)const
{
	if (str == "x" || str == "X")
		return x;
	else if (str == "y" || str == "Y")
		return y;
	else if (str == "z" || str == "Z")
		return z;

	return 0.0f;

}

//==================================================================================================

inline std::ostream&			operator<<		(std::ostream& print, const Vec3& vector)
{
	print << vector.x << "," << vector.y << "," << vector.z;
	return print;
}

inline std::istream&			operator>>		(std::istream& in, Vec3& vector)
{
	in >> vector['x'];
	char c;
	in >> c;
	if ( c != ',')
	{
		vector = Vec3(0.0f,0.0f,0.0f);
		return in;
	}
	in >> vector['y'];
	return in;	
}

//==================================================================================================

inline bool			Vec3::	operator==		(const Vec3& vector)const
{
	if (x == vector.x && y == vector.y && z == vector.z)
		return true;
	return false;
}

inline bool			Vec3::	operator!=		(const Vec3& vector)const
{
	if (x != vector.x || y != vector.y || z != vector.z)
		return true;
	return false;
}

inline bool			Vec3::	operator<=		(const Vec3& vector)const
{
	if (length() <= vector.length())
		return true;
	return false;
}

inline bool			Vec3::	operator<		(const Vec3& vector)const
{
	if (length() < vector.length())
		return true;
	return false;
}

inline bool			Vec3::	operator>		(const Vec3& vector)const
{
	if (length() > vector.length())
		return true;
	return false;
}

inline bool			Vec3::	operator>=		(const Vec3& vector)const
{
	if (length() >= vector.length())
		return true;
	return false;
}

inline bool			Vec3::	are_colinear	(const Vec3& vector, float epsilon )const
{
	return ((*this^vector).length() <= epsilon);
}

//==================================================================================================

inline Vec3 	Vec3::	operator+		(const Vec3& vector)const
{
	return add(vector);
}

inline Vec3&	Vec3::	operator+=		(const Vec3& vector)
{
	return add(vector);
}

inline Vec3 	Vec3::	operator-		(const Vec3& vector)const
{
	return substract(vector);
}

inline Vec3&	Vec3::	operator-=		(const Vec3& vector)
{
	return substract(vector);
}

inline Vec3		Vec3::	operator-		()const
{
	return negate();
}

inline Vec3&	Vec3::	operator-		()
{
	return negate();
}

inline Vec3		Vec3::	operator*		(float _scale)const
{
	return scale(_scale);
}

inline Vec3		Vec3::	operator/		(float scale)const
{
	return divide_by(scale);
}

inline Vec3					operator/		(float scale,const Vec3& vector)
{
	return vector.divide(scale);
}

inline Vec3&	Vec3::	operator*=		(float _scale)
{
	return scale(_scale);
}
inline Vec3&	Vec3::	operator/=		(float scale)
{
	return divide_by(scale);
}
inline Vec3		Vec3:: 	operator++		()const
{
	return enlarge();
}

inline Vec3&	Vec3:: 	operator++		()
{
	return enlarge();
}

inline Vec3		Vec3:: 	operator++		(int)const
{
	return enlarge();
}

inline Vec3&	Vec3:: 	operator++		(int)
{
	return enlarge();
}

inline Vec3		Vec3:: 	operator--		()const
{
	return shrink();
}

inline Vec3&	Vec3:: 	operator--		()
{
	return shrink();
}

inline Vec3		Vec3:: 	operator--		(int)const
{
	return shrink();
}

inline Vec3&	Vec3:: 	operator--		(int)
{
	return shrink();
}

inline float		Vec3::	operator,		(const Vec3& vector)const
{
	return dot_product(vector);
}

inline Vec3		Vec3::	operator^		(const Vec3& vector)const
{
	return cross_product(vector);
}


#endif //__VECTOR3D_INL__
