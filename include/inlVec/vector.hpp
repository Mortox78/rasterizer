#ifndef __VECTOR_HPP__
#define __VECTOR_HPP__

#include <string>
#include <cmath>
#include <iostream>

	struct Vec2;
	struct Vec3;
	struct Vec4;

//==============================VECT2D==============================

	struct Vec2
	{
		typedef Vec2 Point2;

		float x ,y;

		inline Vec2(float x,float y);
		inline Vec2(float xy = 0.f);
		inline Vec2(const Vec2&);
		inline ~Vec2();

		static inline Vec2				zero			(){return Vec2(0.f,0.f);}
		static inline Vec2				up				(){return Vec2(0.0,1.0);}
		static inline Vec2				down 			(){return Vec2(0.0,-1.0);}
		static inline Vec2				right			(){return Vec2(1.0,0.0);}
		static inline Vec2				left			(){return Vec2(-1.0,0.0);}

		inline float			X				()const;
		inline float			Y				()const;
		inline float&			X				();
		inline float&			Y				();


		inline float			length			()const;
		inline float			dot_product		(const Vec2)const;
		inline float			cross_product	(const Vec2)const;
		inline float			dist			(const Vec2)const;
		inline float			angle_btw_vect	(const Vec2)const;

		inline Vec2		add				(const Vec2)const;
		inline Vec2		substract		(const Vec2)const;
		inline Vec2		scale			(float)const;
		inline Vec2		divide_by		(float)const;
		inline Vec2		divide			(float)const;
		inline Vec2		normalize		()const;
		inline Vec2		enlarge			()const;
		inline Vec2		shrink			()const;
		inline Vec2		negate			()const;
		inline Vec2		rotate			(float)const;
		inline Vec2		rotatePoint		(Point2,float)const;
		inline Vec2		normal			()const;


		inline Vec2&		add				(const Vec2);
		inline Vec2&		substract		(const Vec2);
		inline Vec2&		scale			(float);
		inline Vec2&		divide_by		(float);
		inline Vec2&		divide			(float);
		inline Vec2&		normalize		();
		inline Vec2&		enlarge			();
		inline Vec2&		shrink			();
		inline Vec2&		negate			();
		inline Vec2&		rotate			(float);
		inline Vec2&		rotatePoint		(Point2,float);
		inline Vec2&		normal			();


		inline std::string into_string			()const;
		
		inline void			operator=		(float);	
		inline float&		operator[]		(int);
		inline float&		operator[]		(std::string);

		inline bool		operator==		(const Vec2)const;
		inline bool		operator!=		(const Vec2)const;
		inline bool		operator<=		(const Vec2)const;
		inline bool		operator<		(const Vec2)const;
		inline bool		operator>		(const Vec2)const;
		inline bool		operator>=		(const Vec2)const;


			inline Vec2		operator+		(const Vec2)const;
			inline Vec2&	operator+=		(const Vec2);
			inline Vec2		operator-		(const Vec2)const;
			inline Vec2&	operator-=		(const Vec2);
			inline Vec2		operator-		()const;
			inline Vec2&	operator-		();
			inline Vec2		operator*		(float)const;
	friend 	inline Vec2 	operator*		(float,const Vec2);
			inline Vec2		operator/		(float)const;
	friend	inline Vec2		operator/		(float,const Vec2);
			inline Vec2&	operator*=		(float);
			inline Vec2&	operator/=		(float);
			inline Vec2		operator++		()const;
			inline Vec2&	operator++		();
			inline Vec2		operator++		(int)const;
			inline Vec2&	operator++		(int);
			inline Vec2		operator--		()const;
			inline Vec2&	operator--		();
			inline Vec2		operator--		(int)const;
			inline Vec2&	operator--		(int);
			inline float				operator,		(const Vec2)const;
	};

	inline std::string		operator+		(std::string,const Vec2&);
	inline void				operator+=		(std::string&,const Vec2&);
	inline std::ostream& 	operator<<		(std::ostream&,Vec2);
	inline std::istream&	operator>>		(std::istream&,Vec2&);

	inline Vec2			operator*		(float,const Vec2);
	inline Vec2			operator/		(float,const Vec2);

//==============================VECT3D==============================

	struct Vec3
	{
		typedef Vec3 Point3;

		float x, y, z;

		inline Vec3(float x,float y, float z = 0);
		inline Vec3(float xyz = 0.f);
		inline Vec3(const Vec2&, float z = 0);
		inline Vec3(const Vec4&);
		inline Vec3(const Vec3& CopyVector);
		inline ~Vec3();

		static inline Vec3			zero 		(){return Vec3(0.0,0.0,0.0);}

		inline float			X				()const;
		inline float			Y				()const;
		inline float			Z				()const;
		inline float&			X				();
		inline float&			Y				();
		inline float&			Z				();


		inline float			length			()const;
		inline float			dot_product		(const Vec3&)const;
		inline Vec3				cross_product	(const Vec3&)const;
		inline float			dist			(const Vec3&)const;
		inline float			get_area		(const Vec3&)const;


		inline Vec3		add				(const Vec3&)const;
		inline Vec3		substract		(const Vec3&)const;
		inline Vec3		scale			(float scale)const{return Vec3(x * scale, y * scale, z * scale);}
		inline Vec3		divide_by		(float)const;
		inline Vec3		divide			(float)const;
		inline Vec3		normalize		()const;
		inline Vec3		enlarge			()const;
		inline Vec3		shrink			()const;
		inline Vec3		negate			()const;
		inline Vec3		rotate_around	(const Vec3&,float)const;

		inline Vec3&		add				(const Vec3&);
		inline Vec3&		substract		(const Vec3&);
		inline Vec3&		scale			(float);
		inline Vec3&		divide_by		(float);
		inline Vec3&		divide			(float);
		inline Vec3&		normalize		();
		inline Vec3&		enlarge			();
		inline Vec3&		shrink			();
		inline Vec3&		negate			();
		inline Vec3&		rotate_around	(const Vec3&,float);

		inline std::string into_string			()const;
		
		inline void		operator=		(float);	
		inline float&	operator[]		(int);
		inline float&	operator[]		(std::string);
		inline float	operator[]		(int)const;
		inline float	operator[]		(std::string)const;

		inline bool		are_colinear	(const Vec3&,float)const;
		inline bool		operator==		(const Vec3&)const;
		inline bool		operator!=		(const Vec3&)const;
		inline bool		operator<=		(const Vec3&)const;
		inline bool		operator<		(const Vec3&)const;
		inline bool		operator>		(const Vec3&)const;
		inline bool		operator>=		(const Vec3&)const;


			inline Vec3		operator+		(const Vec3&)const;
			inline Vec3&	operator+=		(const Vec3&);
			inline Vec3		operator-		(const Vec3&)const;
			inline Vec3&	operator-=		(const Vec3&);
			inline Vec3		operator-		()const;
			inline Vec3&	operator-		();
			inline Vec3		operator*		(float)const;
	friend 	inline Vec3 	operator*		(float,const Vec3&);
			inline Vec3		operator/		(float)const;
	friend	inline Vec3		operator/		(float,const Vec3&);
			inline Vec3&	operator*=		(float);
			inline Vec3&	operator/=		(float);
			inline Vec3		operator++		()const;
			inline Vec3&	operator++		();
			inline Vec3		operator++		(int)const;
			inline Vec3&	operator++		(int);
			inline Vec3		operator--		()const;
			inline Vec3&	operator--		();
			inline Vec3		operator--		(int)const;
			inline Vec3&	operator--		(int);
			inline Vec3		operator^		(const Vec3&)const;
			inline float		operator,		(const Vec3&)const;
	};

	inline std::string		operator+		(std::string,const Vec3&);
	inline void				operator+=		(std::string&,const Vec3&);
	inline std::ostream& 	operator<<		(std::ostream&,const Vec3&);
	inline std::istream&	operator>>		(std::istream&,Vec3&);

	inline Vec3		operator*		(float _scale,const Vec3& vector){return vector.scale(_scale);}
	inline Vec3		operator/		(float,const Vec3&);

//==============================VECT4D==============================

	struct Vec4
	{

		typedef Vec4 Point4;

		float x, y, z, w;

		inline Vec4(float x,float y, float z, float w = 0);
		inline Vec4(float xyzw = 0.f);
		inline Vec4(const Vec3&, float w = 1);
		inline Vec4(const Vec2&, float z = 0, float w = 1);
		inline Vec4(const Vec4&);
		inline ~Vec4();

		static inline Vec4			zero 		(){return Vec4(0.0f,0.0f,0.0f,0.0f);}

		inline float			X				()const;
		inline float			Y				()const;
		inline float			Z				()const;
		inline float			W				()const;
		inline float&			X				();
		inline float&			Y				();
		inline float&			Z				();
		inline float&			W				();


		inline Vec4&			homogenize		();
		inline float			magnitude		();
		inline float			length			()const;
		inline float			dot_product		(const Vec4&)const;
		inline Vec4				cross_product	(const Vec4&)const;
		inline float			dist			(const Vec4&)const;

		inline Vec4		add				(const Vec4&)const;
		inline Vec4		substract		(const Vec4&)const;
		inline Vec4		scale			(float)const;
		inline Vec4		divide_by		(float)const;
		inline Vec4		divide			(float)const;
		inline Vec4		normalize		()const;
		inline Vec4		enlarge			()const;
		inline Vec4		shrink			()const;
		inline Vec4		negate			()const;

		inline Vec4&	add				(const Vec4&);
		inline Vec4&	substract		(const Vec4&);
		inline Vec4&	scale			(float);
		inline Vec4&	divide_by		(float);
		inline Vec4&	divide			(float);
		inline Vec4&	normalize		();
		inline Vec4&	enlarge			();
		inline Vec4&	shrink			();
		inline Vec4&	negate			();


		std::string into_string			()const;
		
		inline void		operator=		(float);	
		float&			operator[]		(int);
		float&			operator[]		(std::string);
		inline float	operator[]		(int)const;
		inline float	operator[]		(std::string)const;

		bool		operator==		(const Vec4&)const;
		bool		operator!=		(const Vec4&)const;
		bool		operator<=		(const Vec4&)const;
		bool		operator<		(const Vec4&)const;
		bool		operator>		(const Vec4&)const;
		bool		operator>=		(const Vec4&)const;


			inline Vec4		operator+		(const Vec4&)const;
			inline Vec4&	operator+=		(const Vec4&);
			inline Vec4		operator-		(const Vec4&)const;
			inline Vec4&	operator-=		(const Vec4&);
			inline Vec4		operator-		()const;
			inline Vec4&	operator-		();
			inline Vec4		operator*		(float)const;
	friend 	inline Vec4 	operator*		(float,const Vec4&);
			inline Vec4		operator/		(float)const;
	friend	inline Vec4		operator/		(float,const Vec4&);
			inline Vec4&	operator*=		(float);
			inline Vec4&	operator/=		(float);
			inline Vec4		operator++		()const;
			inline Vec4&	operator++		();
			inline Vec4		operator++		(int)const;
			inline Vec4&	operator++		(int);
			inline Vec4		operator--		()const;
			inline Vec4&	operator--		();
			inline Vec4		operator--		(int)const;
			inline Vec4&	operator--		(int);
			inline Vec4		operator^		(const Vec4&)const;
			inline float		operator,		(const Vec4&)const;
	};

	inline std::string		operator+		(std::string,const Vec4&);
	inline void				operator+=		(std::string&,const Vec4&);
	inline std::ostream& 	operator<<		(std::ostream&,Vec4&);
	inline std::istream&	operator>>		(std::istream&,Vec4&);

	inline Vec4				operator*		(float,const Vec4&);
	inline Vec4				operator/		(float,const Vec4&);

	inline float	degrees_to_radian	(float angle){return (angle * M_PI)/180;}

	#include "vector2D.inl"
	#include "vector3D.inl"
	#include "vector4D.inl"

#endif //__VECTOR_HPP__
