#ifndef __SUBMATRIX_INL__
#define __SUBMATRIX_INL__

#include "matrix.h"

//================================================================================== 
template<typename T>
SubMatrix<T>::		SubMatrix					(unsigned int l, unsigned int c):
	n 		{l},
	m 		{c},
	array 	{n || m !=  0 ? new T[n*m] : nullptr}
{
}

template<typename T>
SubMatrix<T>::		SubMatrix						(const SubMatrix<T>& copy_SubMatrix):
	n 		{copy_SubMatrix.n},
	m 		{copy_SubMatrix.m},
	array	{n || m != 0 ? new T[n*m] : nullptr}
{
	if (n == copy_SubMatrix.n && m == copy_SubMatrix.m)
		for (unsigned int i = 0; i < (n*m); i++)
				array[i] = copy_SubMatrix.array[i];
}

template<typename T>
SubMatrix<T>::		~SubMatrix						()
{
	if (array != nullptr)
		delete[] array;
}

//==================================================================================

template<typename T>
inline SubMatrix<T>			SubMatrix<T>:: 	transponate		()const
{
	
	SubMatrix<T> transponate(m,n);

	for (unsigned int i = 0; i < n ; i++)
		for (unsigned int j = 0; j < m; j++)
			transponate[i][j] = this->accessor(j,i);

	return transponate;
}

template<typename T>
inline T				SubMatrix<T>::	copy			(unsigned int i)const
{
	return array[i];
}

//==================================================================================

template<typename T>
inline T						SubMatrix<T>::	det				()const
{
	if (n != m)
	{
		return 0;
	}
	else if (n == 1)
	{
		return array[0];
	}
	else if (n == 2)
	{
		return ((accessor(0,0) * accessor(1,1)) - (accessor(1,0) * accessor(0,1)));
	}
	else if (n == 3)//3				//2
	{
		return (	(accessor(0,0) * ((accessor(1,1) * accessor(2,2)) - (accessor(2,1) * accessor(1,2))))
				- 	(accessor(0,1) * ((accessor(1,0) * accessor(2,2)) - (accessor(2,0) * accessor(1,2))))
				+ 	(accessor(0,2) * ((accessor(1,0) * accessor(2,1)) - (accessor(2,0) * accessor(1,1)))));
	}
	else if (n == 4)//4				//3				  //2
	{
			return (	(accessor(0,0) * 
					(
						(accessor(1,1) * ((accessor(2,2) * accessor(3,3)) - (accessor(3,2) * accessor(2,3))))
					- 	(accessor(1,2) * ((accessor(2,1) * accessor(3,3)) - (accessor(3,1) * accessor(2,3))))
					+ 	(accessor(1,3) * ((accessor(2,1) * accessor(3,2)) - (accessor(3,1) * accessor(2,2))))
					)
				-	(accessor(0,1) * 
					(
						(accessor(1,0) * ((accessor(2,2) * accessor(3,3)) - (accessor(3,2) * accessor(2,3))))
					- 	(accessor(1,2) * ((accessor(2,0) * accessor(3,3)) - (accessor(3,0) * accessor(2,3))))
					+ 	(accessor(1,3) * ((accessor(2,0) * accessor(3,2)) - (accessor(3,0) * accessor(2,2))))
					))
				+	(accessor(0,2) * 
					(
						(accessor(1,0) * ((accessor(2,1) * accessor(3,3)) - (accessor(3,1) * accessor(2,3))))
					- 	(accessor(1,1) * ((accessor(2,0) * accessor(3,3)) - (accessor(3,0) * accessor(2,3))))
					+ 	(accessor(1,3) * ((accessor(2,0) * accessor(3,1)) - (accessor(3,0) * accessor(2,1))))
					))
				-	(accessor(0,3) * 
					(
						(accessor(1,0) * ((accessor(2,1) * accessor(3,2)) - (accessor(3,1) * accessor(2,2))))
					- 	(accessor(1,1) * ((accessor(2,0) * accessor(3,2)) - (accessor(3,0) * accessor(2,2))))
					+ 	(accessor(1,2) * ((accessor(2,0) * accessor(3,1)) - (accessor(3,0) * accessor(2,1))))
					))
					));
	}
	else
	{
		T det = 0.f;
		for (unsigned int i = 0 ; i < m; i++)
		{
			SubMatrix<T> Sub_Matrix = GetSubMatrix(*this,i,0);
			det +=	accessor(0,i) * Sub_Matrix.det() * std::pow(-1,i);
		}
		return det;
	}
}

template<typename T>
inline SubMatrix<T>	SubMatrix<T>::	GetSubMatrix	(const SubMatrix<T>& Sub_Matrix,unsigned int excolumn ,unsigned int excline)const
{
	SubMatrix<T> NewMatrix(Sub_Matrix.n-1,Sub_Matrix.m-1);

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
					NewMatrix[x][y] = Sub_Matrix.accessor(i,j);
					y++;
				}
			}
			y = 0;
			x++;
		}
	}	

	return NewMatrix;
}

//==================================================================================

template<typename T>
inline T*			SubMatrix<T>::	operator[]		(unsigned int u)
{
	return &this->array[u * m];
}

template<typename T>
inline void			SubMatrix<T>::	operator=		(const SubMatrix<T>& CopyMatrix)
{
	if (array != nullptr)
		delete[] array;

	array = new T[CopyMatrix.n * CopyMatrix.n];
	n = CopyMatrix.n;
	m = CopyMatrix.m;

	for (unsigned int i = 0; i < (n*m); i++)
				array[i] = CopyMatrix.array[i];

}

//==================================================================================

template<typename T>
void			SubMatrix<T>::	display			()const
{
	for (unsigned int i = 0; i < n; i++)
	{

			for (unsigned int k = 0; k < m ; k++)
				std::cout << "==-";
			std::cout << std::endl << "|";

		for (unsigned int j = 0; j < m; j++)
		{
			if (j != 0)
				std::cout << " |" << this->accessor(i,j);
			else
				std::cout << this->accessor(i,j);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

#endif //__SUBMATRIX_INL__
