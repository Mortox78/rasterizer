#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <array>
#include <cmath>
#include "inlVec/vector.hpp"

	template<typename T, unsigned int row = 0, unsigned int column = 0>
	class Matrix
	{
		private:
			public:
			std::array<T,row*column>	array;
			//==========================================
			Matrix<T,row,column>	();
			Matrix<T,row,column>	(const Matrix<T,row,column>*);
			~Matrix<T,row,column>	();

		//=========================================================
		inline static	Matrix<T,row,column>	identity	();
		inline static	Matrix<T,row,column>	zero		();
			
			//==========================================================
			inline std::array<T,row*column>	matrix		()const;
			inline T							copy		(unsigned int)const;
			inline T&							copy		(unsigned int);


			//==================================================
			inline T&		accessor		(unsigned int l, unsigned int c){return array[(l * column) + c];}
			inline T		accessor		(unsigned int l, unsigned int c)const{return array[(l * column) + c];}

			//======================================================================
			inline Matrix<T,row,column>			transponate		()const;
			inline T							det				()const;
			inline Matrix<T,row,column>&		add				(const Matrix<T,row,column>&);
			inline Matrix<T,row,column>			add				(const Matrix<T,row,column>&)const;
			inline Matrix<T,row,column>&		substract		(const Matrix<T,row,column>&);
			inline Matrix<T,row,column>			substract		(const Matrix<T,row,column>&)const;
			inline Matrix<T,row,column>&		multiplicate	(const Matrix<T,row,column>&);
			inline Matrix<T,row,column>&		multiplicate	(const Matrix<T,row,column>&)const;


			template<unsigned int c>
			inline Matrix<T,row,c>			multiplicate	(const Matrix<T,column,c>& multrix)const	
			{
				Matrix<T,row,c> new_Matrix;
   
				for	(unsigned int i = 0; i < row; i++)
				{
					for (unsigned int j = 0; j < c ; j++)
					{
						for (unsigned int k = 0; k < column ; k++)
						{

							new_Matrix.array[((i*c)+j)] += this->array[(i * column) + k] * multrix.array[(k * c) + j];	
						}
					}
				}
				return new_Matrix;
			}

			inline Matrix<T,row,column>			multiplicate	(T)const;
			inline Matrix<T,row,column>&		multiplicate	(T);
			inline Matrix<T,row,column>			divide			(T)const;
			inline Matrix<T,row,column>&		divide			(T);


			//==========================================================================
			inline T						getMinor			(unsigned int,unsigned int)const;
			inline T						getCofactor			(unsigned int,unsigned int)const;
			inline Matrix<T,row,column>		getComatrix			()const;
			inline Matrix<T,row,column>		getConjugateMatrix	()const;
			inline Matrix<T,row,column>		getInverseMatrix	()const;
			
			template<unsigned int c>
			inline Matrix<T,row,c>			SystemResolve		(const Matrix<T,row,c>& ResultMatrix)const
			{
				Matrix<T,row,c> 		UnknownMatrix;
			   	Matrix<T,row,column> 	InverseMatrix = getInverseMatrix();

				UnknownMatrix = InverseMatrix * ResultMatrix;

				return UnknownMatrix;
			}

			//=============================
			inline void		display		()const;
			
			//==========================================================================
			inline T*							operator[]			(unsigned int);
			inline Matrix<T,row,column>&		operator+=			(const Matrix<T,row,column>&);
			inline Matrix<T,row,column>			operator+			(const Matrix<T,row,column>&)const;
			inline Matrix<T,row,column>&		operator-=			(const Matrix<T,row,column>&);
			inline Matrix<T,row,column>			operator-			(const Matrix<T,row,column>&)const;
			inline Matrix<T,row,column>			operator*			(const Matrix<T,row,column>&)const;
			inline Matrix<T,row,column>&		operator*=			(const Matrix<T,row,column>&);
			
			template<unsigned int c>
			inline Matrix<T,row,c>				operator*			(const Matrix<T,column,c>& multrix)const
			{
				return this->multiplicate(multrix);
			}
			

			inline Matrix<T,row,column>			operator*			(T)const;
			inline Matrix<T,row,column>&		operator*=			(T);
			inline Matrix<T,row,column>			operator/			(T)const;
			inline Matrix<T,row,column>&		operator/=			(T);

	};





	template<typename T>
	struct	SubMatrix
	{
			unsigned int n;
			unsigned int m;
		private:
			T*	 array;
		public:

			//==========================================
			SubMatrix<T>	(unsigned int l = 0,unsigned int c = 0);
			SubMatrix<T>	(const SubMatrix<T>&);
			~SubMatrix<T>	();
			
			//==================================================
			inline T&		accessor		(unsigned int l, unsigned int c) 	  {return array[(l * m) + c];}
			inline T		accessor		(unsigned int l, unsigned int c)const {return array[(l * m) + c];}
			inline T		copy			(unsigned int)const;

			//======================================================================
			inline SubMatrix<T>	transponate		()const;
			inline T				det			()const;

			inline SubMatrix<T>	GetSubMatrix	(const SubMatrix<T>&,unsigned int,unsigned int)const;
			//=============================
			void		display		()const;
			
			//==========================================================================
			inline T*				operator[]			(unsigned int);
			inline void				operator=			(const SubMatrix<T>&);

	};




	#include "submatrix.inl"

	template<typename T, unsigned int row, unsigned int column>
	SubMatrix<T>	GetSubMatrix	(const Matrix<T,row,column>& Matrix,unsigned int excolumn ,unsigned int excline)
	{
		SubMatrix<T> NewMatrix (row - 1, column - 1);
		unsigned int x = 0;
		unsigned int y = 0;

		for (unsigned int i = 0; i <= NewMatrix.n; i++)
		{
			if (excline != i)
			{
				for (unsigned int j = 0; j <= NewMatrix.m; j++)
				{
					if (j != excolumn)
					{
						NewMatrix.accessor(x,y) = Matrix.accessor(i,j);	
						y++;
					}
				}
				y = 0;
				x++;
				}
			}
			return NewMatrix;
		}





		#include "matrix.inl"

		template<typename T>
		class Matrix4 : public Matrix<T,4,4>
		{
			public:
				Matrix4();
				Matrix4(const Matrix<T,4,4>&);
				Matrix4(const Matrix4&);
				~Matrix4();

			//=========================================================
			inline static	Matrix4<T>	identity	();
			inline static	Matrix4<T>	zero		();

			//==================================================
			inline T&		accessor		(unsigned int l, unsigned int c){return this->array[(l * 4) + c];}
			inline T		accessor		(unsigned int l, unsigned int c)const{return this->array[(l * 4) + c];}
	
			//==========================================================================

			inline Vec4	multiplicate	(const Vec4&)const;
			inline Vec4	operator*		(const Vec4&)const;
			
			Matrix4	operator* (const Matrix4&)const;


			static inline Matrix4<T> CreateTRSMatrix						(const Vec3&, const Vec3&, const Vec3&);
			static inline Matrix4<T> CreateScaleMatrix 						(const Vec3&);
			static inline Matrix4<T> CreateTranslationMatrix				(const Vec3&);
			static inline Matrix4<T> CreateFixedAngleEulerRotationMatrix	(const Vec3&);

			static inline Matrix4<T> CreateXRotationMatrix	(const float&);
			static inline Matrix4<T> CreateYRotationMatrix	(const float&);
			static inline Matrix4<T> CreateZRotationMatrix	(const float&);

		};

	#include "matrix4.inl"

#endif //__MATRIX_H__
