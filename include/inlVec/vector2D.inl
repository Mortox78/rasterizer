#ifndef __VECTOR2DINL__
#define __VECTOR2DINL__

#include "vector.hpp"



//==================================================================================================

inline Vec2:: Vec2		(float _x,float _y):
	x {_x},
	y {_y}
{
}

inline Vec2:: Vec2		(const Vec2& copyVector):
	x {copyVector.x},
	y {copyVector.y}
{
}

inline Vec2::  Vec2		(float xy):
	x {xy},
	y {xy}
{
}

inline Vec2:: ~Vec2	()
{
}

//==================================================================================================

inline float 	Vec2::		X		()const
{
	return this->x;
}

inline float 	Vec2::		Y		()const
{
	return this->y;
}

inline float&		Vec2::		X		()
{
	return this->x;
}

inline float&		Vec2::		Y		()
{
	return this->y;
}

//==================================================================================================

inline float	Vec2::		dot_product		(const Vec2 vect)const
{
	return (x * vect.x) + (y * vect.y);
}

inline float	Vec2::		length			()const
{
	return sqrt(pow(x,2)+pow(y,2));
}

inline float	Vec2::		cross_product	(const Vec2 vect)const
{
	return (x * vect.y) - (y * vect.x);	
}

inline float	Vec2::		dist			(const Vec2 vect)const
{
	return sqrtf( powf( (vect.x - x), 2) + powf( (vect.y - y), 2) );
}

inline float	Vec2::		angle_btw_vect	(const Vec2 vect)const
{
	if ( *this == Vec2(0.0f,0.0f) || vect == Vec2(0.0f,0.0f))
		return 0.f;

	return acosf(( *this , vect ) / ( this->length() * vect.length() ));
}

//==================================================================================================

inline Vec2		Vec2::	add					(const Vec2 vector)const
{
	return Vec2(x + vector.x,y + vector.y);
}

inline Vec2		Vec2::	substract			(const Vec2 vector)const
{
	return Vec2(x - vector.x,y - vector.y);
}

inline Vec2		Vec2::	scale				(float scale)const
{
	return Vec2(x * scale, y * scale);
}

inline Vec2		Vec2::	divide_by			(float scale)const
{
	return Vec2(x / scale, y / scale);
}

inline Vec2		Vec2::	divide				(float scale)const
{
	return Vec2(scale / x,scale/ y);
}


inline Vec2	Vec2::	normalize			()const
{
	float length = this->length();
	return Vec2(x/length,y/length);
}

inline Vec2	Vec2::	enlarge				()const
{
	float length = this->length();
	float x = x;
	float y = y;
	return Vec2((x *= ((length + 1) / length)),(y *= ((length + 1) / length)));
}

inline Vec2	Vec2::	shrink				()const
{
	float length = this->length();
	float x = x;
	float y = y;
	return Vec2((x *= ((length - 1) / length)),(y *= ((length - 1) / length)));
}

inline Vec2	Vec2::	negate				()const
{
	return Vec2(-x,-y);
}

inline Vec2	Vec2::	rotate				(float angle)const
{
	float cos_angle = cosf(angle);
	float sin_angle = sinf(angle);
	return Vec2( (x * cos_angle) - (y * sin_angle), (x * sin_angle) + (y * cos_angle));
}

inline Vec2	Vec2::	rotatePoint			(Point2 point, float angle)const
{
		Vec2	vect_btw_points	 =	*this - point;

		vect_btw_points.rotate(angle);

		Point2 		rotated_point 	 = vect_btw_points + point;

		return rotated_point;
}

inline Vec2	Vec2::	normal				()const
{
	return Vec2(-y,x);
}

//==================================================================================================

inline Vec2&			Vec2::	add				(const Vec2 vector)
{
	x = x + vector.x;
	y = y + vector.y;
	return *this;
}

inline Vec2&			Vec2::	substract		(const Vec2 vector)
{
	x = x - vector.x;
	y = y - vector.y;
	return *this;
}

inline Vec2&			Vec2::	scale			(float scale)
{
	x = x * scale;
	y = y * scale;
	return *this;
}

inline Vec2&			Vec2::	divide_by		(float scale)
{
	x = x / scale;
	y = y /	scale;
	return *this;
}

inline Vec2&			Vec2::	divide			(float scale)
{
	x = scale / x;
	y = scale / y;
	return *this;
}

inline Vec2&		Vec2::	normalize			()
{
	float length = this->length();
	x = x/length;
	y = y/length;
	return *this;
}

inline Vec2&		Vec2::	enlarge				()
{
	float length = this->length();
	x *= (length + 1) / length; 
	y *= (length + 1) / length;
	return *this;
}

inline Vec2&		Vec2::	shrink				()
{
	float length = this->length();
	x *= (length - 1) / length; 
	y *= (length - 1) / length;
	return *this;
}

inline Vec2&		Vec2::	negate				()
{
	x = -x;
	y = -y;
	return *this;
}


inline Vec2&		Vec2::	rotate				(float angle)
{
	float cos_angle = cosf(angle);
	float sin_angle = sinf(angle);
	x = (x * cos_angle) - (y * sin_angle);
	y = (x * sin_angle) + (y * cos_angle);
	return *this;
}

inline Vec2&		Vec2::	rotatePoint			(Point2 point, float angle)
{
		Vec2 vect_btw_points =	*this - point;

		vect_btw_points.rotate(angle);

		*this = vect_btw_points + point;

		return *this;
}

inline Vec2&		Vec2::	normal				()
{
	*this = Vec2 (-y,x);
	return *this;
}
//==================================================================================================

inline 	void 		Vec2::		operator=		(float v)
{
	*this = v;
}

inline std::string			operator+		(std::string str,const Vec2& vector)
{
	return str + vector.into_string();
}

inline void				operator+=		(std::string& str,const Vec2& vector)
{
	str = str + vector.into_string();
}

inline 	std::string	Vec2::	into_string		()const
{
	std::string str = "x:" + std::to_string(x) + ", y:" + std::to_string(y);
  	return str;	
}

inline float& 	Vec2::		operator[]		(int i)
{
	if (i == 0 || i == 'x' || i == 'X')
		return x;

	else if (i == 1 || i == 'y' || i == 'Y')
		return y;

	float f 	= 0.0f;
	float& t	= f;
	return t;
}

inline float&		Vec2::		operator[]		(std::string str)
{
	if (str == "x" || str == "X")
		return x;

	else if (str == "y" || str == "Y")
		return y;

	float f 	= 0.0f;
	float& t	= f;
	return t;

}

inline std::ostream&	operator<<		(std::ostream& print, Vec2 vector)
{
	print << vector.x << "," << vector.y;
	return print;
}

inline std::istream&	operator>>		(std::istream& in, Vec2& vector)
{
	in >> vector['x'];
	char c;
	in >> c;
	if ( c != ',')
	{
		vector = Vec2(0.0f,0.0f);
		return in;
	}
	in >> vector['y'];
	return in;	
}

//==================================================================================================

inline bool	Vec2::		operator==		(const Vec2 vector)const
{
	if (x == vector.x && y == vector.y)
		return true;
	return false;
}

inline bool	Vec2::		operator!=		(const Vec2 vector)const
{
	if (x != vector.x || y != vector.y)
		return true;
	return false;
}

inline bool	Vec2::		operator<=		(const Vec2 vector)const
{
	if (this->length() <= vector.length())
		return true;
	return false;
}

inline bool	Vec2::		operator<		(const Vec2 vector)const
{
	if (this->length() < vector.length())
		return true;
	return false;
}

inline bool	Vec2::		operator>		(const Vec2 vector)const
{
	if (this->length() > vector.length())
		return true;
	return false;
}

inline bool	Vec2::		operator>=		(const Vec2 vector)const
{
	if (this->length() >= vector.length())
		return true;
	return false;
}

//==================================================================================================

inline Vec2		Vec2::		operator+		(const Vec2 vector)const
{
	return this->add(vector);
}

inline Vec2&		Vec2::		operator+=		(const Vec2 vector)
{
	return this->add(vector);
}

inline Vec2		Vec2::		operator-		(const Vec2 vector)const
{
	return this->substract(vector);
}

inline Vec2&		Vec2::		operator-=		(const Vec2 vector)
{
	return this->substract(vector);
}

inline Vec2	Vec2::		operator-		()const
{
	return this->negate();
}

inline Vec2&		Vec2::		operator-		()
{
	return this->negate();
}

inline Vec2	Vec2::	operator*		(float scale)const
{
	return this->scale(scale);
}

inline Vec2		operator*		(float scale,const Vec2 vector)
{
	return vector.scale(scale);
}

inline Vec2	Vec2::	operator/		(float scale)const
{
	return this->divide_by(scale);
}

inline Vec2		operator/		(float scale,const Vec2 vector)
{
	return vector.divide(scale);
}

inline Vec2&		Vec2::	operator*=		(float scale)
{
	return this->scale(scale);
}
inline Vec2&		Vec2::	operator/=		(float scale)
{
	return this->divide_by(scale);
}
inline Vec2	Vec2:: 	operator++		()const
{
	return this->enlarge();
}

inline Vec2&		Vec2:: 	operator++		()
{
	return this->enlarge();
}

inline Vec2	Vec2:: 	operator++		(int)const
{
	return this->enlarge();
}

inline Vec2&		Vec2:: 	operator++		(int)
{
	return this->enlarge();
}

inline Vec2	Vec2:: 	operator--		()const
{
	return this->shrink();
}

inline Vec2&		Vec2:: 	operator--		()
{
	return this->shrink();
}

inline Vec2	Vec2:: 	operator--		(int)const
{
	return this->shrink();
}

inline Vec2&	Vec2:: 	operator--		(int)
{
	return this->shrink();
}

inline float		Vec2::	operator,		(const Vec2 vector)const
{
	return this->dot_product(vector);
}

#endif //__VECTOR2D_INL__
