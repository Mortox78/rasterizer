#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <iostream>
#include <string>


struct Vec2
{
	typedef Vec2 Point2;

	float x, y;

	static Vec2 zero;
	static Vec2 up;
	static Vec2 down;
	static Vec2 right;
	static Vec2 left;

	Vec2(float x,float y);
	Vec2(float xy = 0.f);
	Vec2(const Vec2&);
	~Vec2();

	float			X				()const;
	float			Y				()const;
	float&			X				();
	float&			Y				();
	float			length			()const;
	float			dot_product		(const Vec2)const;
	float			cross_product	(const Vec2)const;
	float			dist			(const Vec2)const;
	float			angle_btw_vect	(const Vec2)const;

	Vec2		add				(const Vec2)const;
	Vec2		substract		(const Vec2)const;
	Vec2		scale			(float)const;
	Vec2		divide_by		(float)const;
	Vec2		divide			(float)const;
	Vec2		normalize		()const;
	Vec2		enlarge			()const;
	Vec2		shrink			()const;
	Vec2		negate			()const;
	Vec2		rotate			(float)const;
	Vec2		rotatePoint		(Point2,float)const;
	Vec2		normal			()const;

	Vec2&		add				(const Vec2);
	Vec2&		substract		(const Vec2);
	Vec2&		scale			(float);
	Vec2&		divide_by		(float);
	Vec2&		divide			(float);
	Vec2&		normalize		();
	Vec2&		enlarge			();
	Vec2&		shrink			();
	Vec2&		negate			();
	Vec2&		rotate			(float);
	Vec2&		rotatePoint		(Point2,float);
	Vec2&		normal			();

	std::string into_string			()const;
	
	void		operator=		(float);	
	float&		operator[]		(int);
	float&		operator[]		(std::string);
	bool		operator==		(const Vec2)const;
	bool		operator!=		(const Vec2)const;
	bool		operator<=		(const Vec2)const;
	bool		operator<		(const Vec2)const;
	bool		operator>		(const Vec2)const;
	bool		operator>=		(const Vec2)const;

	Vec2	operator+		(const Vec2)const;
	Vec2&	operator+=		(const Vec2);
	Vec2	operator-		(const Vec2)const;
	Vec2&	operator-=		(const Vec2);
	Vec2	operator-		()const;
	Vec2&	operator-		();
	Vec2	operator*		(float)const;
	friend 	Vec2 	operator*		(float,const Vec2);
	Vec2	operator/		(float)const;
	friend	Vec2	operator/		(float,const Vec2);
	Vec2&	operator*=		(float);
	Vec2&	operator/=		(float);
	Vec2	operator++		()const;
	Vec2&	operator++		();
	Vec2	operator++		(int)const;
	Vec2&	operator++		(int);
	Vec2	operator--		()const;
	Vec2&	operator--		();
	Vec2	operator--		(int)const;
	Vec2&	operator--		(int);
	float		operator,		(const Vec2)const;

};

float		degrees_to_radian	(float);

std::string		operator+		(std::string,const Vec2&);
void			operator+=		(std::string&,const Vec2&);
std::ostream& 	operator<<		(std::ostream&,Vec2);
std::istream&	operator>>		(std::istream&,Vec2&);

Vec2		operator*		(float,const Vec2);
Vec2		operator/		(float,const Vec2);

struct Vec4;

	struct Vec3
	{
		typedef Vec3 Point3;

	
			float x, y, z;
		


		static Vec3 zero;

		Vec3(float x,float y, float z);
		Vec3(float xyz = 0.f);
		Vec3(const Vec2&, float _z);
		Vec3(const Vec3&);
		Vec3(const Vec4&);
		~Vec3();

		float			X				()const;
		float			Y				()const;
		float			Z				()const;
		float&			X				();
		float&			Y				();
		float&			Z				();


		float			length			()const;
		float			dot_product		(const Vec3&)const;
		Vec3			cross_product	(const Vec3&)const;
		float			dist			(const Vec3&)const;
		float			get_area		(const Vec3&)const;

		Vec3		add				(const Vec3&)const;
		Vec3		substract		(const Vec3&)const;
		Vec3		scale			(float)const;
		Vec3		divide_by		(float)const;
		Vec3		divide			(float)const;
		Vec3		normalize		()const;
		Vec3		enlarge			()const;
		Vec3		shrink			()const;
		Vec3		negate			()const;

		Vec3&		add				(const Vec3&);
		Vec3&		substract		(const Vec3&);
		Vec3&		scale			(float);
		Vec3&		divide_by		(float);
		Vec3&		divide			(float);
		Vec3&		normalize		();
		Vec3&		enlarge			();
		Vec3&		shrink			();
		Vec3&		negate			();


		std::string into_string			()const;
		
		void		operator=		(float);	
		float&		operator[]		(int);
		float&		operator[]		(std::string);

		bool		operator==		(const Vec3&)const;
		bool		operator!=		(const Vec3&)const;
		bool		operator<=		(const Vec3&)const;
		bool		operator<		(const Vec3&)const;
		bool		operator>		(const Vec3&)const;
		bool		operator>=		(const Vec3&)const;


			Vec3	operator+		(const Vec3&)const;
			Vec3&	operator+=		(const Vec3&);
			Vec3	operator-		(const Vec3&)const;
			Vec3&	operator-=		(const Vec3&);
			Vec3	operator-		()const;
			Vec3&	operator-		();
			Vec3	operator*		(float)const;
	friend 	Vec3 	operator*		(float,const Vec3&);
			Vec3	operator/		(float)const;
	friend	Vec3	operator/		(float,const Vec3&);
			Vec3&	operator*=		(float);
			Vec3&	operator/=		(float);
			Vec3	operator++		()const;
			Vec3&	operator++		();
			Vec3	operator++		(int)const;
			Vec3&	operator++		(int);
			Vec3	operator--		()const;
			Vec3&	operator--		();
			Vec3	operator--		(int)const;
			Vec3&	operator--		(int);
			Vec3	operator^		(const Vec3&)const;
			float	operator,		(const Vec3&)const;
	};

	std::string		operator+		(std::string,const Vec3&);
	void			operator+=		(std::string&,const Vec3&);
	std::ostream& 	operator<<		(std::ostream&,Vec3&);
	std::ostream& 	operator<<		(std::ostream&,const Vec3&);
	std::istream&	operator>>		(std::istream&,Vec3&);

	Vec3		operator*		(float,const Vec3&);
	Vec3		operator/		(float,const Vec3&);




	struct Vec4
	{

		typedef Vec4 Point4;

			float x, y, z, w;

		static Vec4 zero;

		Vec4(float x,float y, float z, float w = 1);
		Vec4(float xyzw = 0.f);
		Vec4(const Vec3&, float w = 1);
		Vec4(const Vec2&, float z = 0, float w = 1);
		Vec4(const Vec4&);
		~Vec4();

		float			X				()const;
		float			Y				()const;
		float			Z				()const;
		float			W				()const;
		float&			X				();
		float&			Y				();
		float&			Z				();
		float&			W				();


		Vec4&			homogenize		();
		float			magnitude		();
		float			length			()const;
		float			dot_product		(const Vec4&)const;
		Vec4			cross_product	(const Vec4&)const;
		float			dist			(const Vec4&)const;
		float			get_area		(const Vec4&)const;


		Vec4		add				(const Vec4&)const;
		Vec4		substract		(const Vec4&)const;
		Vec4		scale			(float)const;
		Vec4		divide_by		(float)const;
		Vec4		divide			(float)const;
		Vec4		normalize		()const;
		Vec4		enlarge			()const;
		Vec4		shrink			()const;
		Vec4		negate			()const;

		Vec4&		add				(const Vec4&);
		Vec4&		substract		(const Vec4&);
		Vec4&		scale			(float);
		Vec4&		divide_by		(float);
		Vec4&		divide			(float);
		Vec4&		normalize		();
		Vec4&		enlarge			();
		Vec4&		shrink			();
		Vec4&		negate			();


		std::string into_string			()const;
		
		void		operator=		(float);	
		float&		operator[]		(int);
		float		operator[]		(int)const;
		float&		operator[]		(std::string);

		bool		operator==		(const Vec4&)const;
		bool		operator!=		(const Vec4&)const;
		bool		operator<=		(const Vec4&)const;
		bool		operator<		(const Vec4&)const;
		bool		operator>		(const Vec4&)const;
		bool		operator>=		(const Vec4&)const;


			Vec4	operator+		(const Vec4&)const;
			Vec4&	operator+=		(const Vec4&);
			Vec4	operator-		(const Vec4&)const;
			Vec4&	operator-=		(const Vec4&);
			Vec4	operator-		()const;
			Vec4&	operator-		();
			Vec4	operator*		(float)const;
	friend 	Vec4 	operator*		(float,const Vec4&);
			Vec4	operator/		(float)const;
	friend	Vec4	operator/		(float,const Vec4&);
			Vec4&	operator*=		(float);
			Vec4&	operator/=		(float);
			Vec4	operator++		()const;
			Vec4&	operator++		();
			Vec4	operator++		(int)const;
			Vec4&	operator++		(int);
			Vec4	operator--		()const;
			Vec4&	operator--		();
			Vec4	operator--		(int)const;
			Vec4&	operator--		(int);
			Vec4	operator^		(const Vec4&)const;
			float		operator,		(const Vec4&)const;
	};

	std::string		operator+		(std::string,const Vec4&);
	void			operator+=		(std::string&,const Vec4&);
	std::ostream& 	operator<<		(std::ostream&,Vec4&);
	std::istream&	operator>>		(std::istream&,Vec4&);

	Vec4		operator*		(float,const Vec4&);
	Vec4		operator/		(float,const Vec4&);





#endif //__VECTOR_HPP__
