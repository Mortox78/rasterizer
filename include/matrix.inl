#ifndef __MATRIX_INL__
#define __MATRIX_INL__

#include "matrix.h"


//==================================================================================
template<typename T, unsigned int row, unsigned int column>
Matrix<T,row,column>::		Matrix					()
{
	array.fill(0.0f);
}

template<typename T, unsigned int row, unsigned int column>
Matrix<T,row,column>::		Matrix						(const Matrix* copy_Matrix)
{
	if (row == copy_Matrix.row && column == copy_Matrix.column)
		for (unsigned int i = 0; i < (row*column); i++)
				array[i] = copy_Matrix->copy(i);
}

template<typename T, unsigned int row, unsigned int column>
Matrix<T,row,column>::		~Matrix						()
{
}

//==================================================================================

template<typename T, unsigned int row, unsigned int column>
inline std::array<T,row*column>		Matrix<T,row,column>::	matrix			()const
{
	return array;
}

template<typename T, unsigned int row, unsigned int column>
inline T			Matrix<T,row,column>::	copy			(unsigned int i)const
{

	return array[i];
}

template<typename T, unsigned int row, unsigned int column>
inline T&			Matrix<T,row,column>::	copy			(unsigned int i)
{
	return array[i];
}

//=================================================================================

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>			Matrix<T,row,column>::	identity		()
{
	Matrix<T,row,column> M;
	for (unsigned int i = 0; i < (column * row); i++)
			if (i % (column + 1) == 0)
				M.array[i] = 1;
			else
				M.array[i] = 0;

	return M;
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>			Matrix<T,row,column>::	zero			()
{
	Matrix<T,row,column> M;
	return M;
}

//==================================================================================

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>			Matrix<T,row,column>:: 	transponate		()const
{
	Matrix<T,column,row> transponate;

	for (unsigned int i = 0; i < row ; i++)
		for (unsigned int j = 0; j < column; j++)
			transponate[i][j] = accessor(j,i);

	return transponate;
}

//==================================================================================

template<typename T, unsigned int row, unsigned int column>
inline T						Matrix<T,row,column>::	det				()const
{
	if (row != column)
	{
		return 0;
	}
	switch (row)
	{
		case 1:
			return array[0];
		case 2:
			return ((accessor(0,0) * accessor(1,1)) - (accessor(1,0) * accessor(0,1)));
		case 3:
			return ((accessor(0,0) * ((accessor(1,1) * accessor(2,2)) - (accessor(2,1) * accessor(1,2))))
				- 	(accessor(0,1) * ((accessor(1,0) * accessor(2,2)) - (accessor(2,0) * accessor(1,2))))
				+ 	(accessor(0,2) * ((accessor(1,0) * accessor(2,1)) - (accessor(2,0) * accessor(1,1)))));
		case 4:
			return ((accessor(0,0) * 
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
		default:
			T det = 0.f;
			for (unsigned int i = 0 ; i < column; i++)
			{
				SubMatrix<T> Sub_Matrix = GetSubMatrix(*this,i,0);
				det +=	accessor(0,i) * Sub_Matrix.det() * std::pow(-1,i);
			}
			return det;
		break;
		}
}
//==================================================================================

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>&			Matrix<T,row,column>::	add				(const Matrix& add_matrix)
{

	for (unsigned int i = 0; i < (row*column); i++)
		this->array[i] = this->array[i] + add_matrix.array[i];
	return *this;
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>			Matrix<T,row,column>::	add				(const Matrix& add_matrix)const
{
	Matrix<T,row,column> new_Matrix; 

	for (unsigned int i = 0; i < (row*column); i++)
		new_Matrix.array[i] = this->array[i] + add_matrix.array[i];
	return new_Matrix;
}

//==================================================================================

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>&			Matrix<T,row,column>::	substract				(const Matrix& add_matrix)
{
	for (unsigned int i = 0; i < (row*column); i++)
		this->array[i] = this->array[i] - add_matrix.array[i];
	return *this;
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>			Matrix<T,row,column>::	substract				(const Matrix& add_matrix)const
{
	Matrix<T,row,column> new_Matrix; 

	for (unsigned int i = 0; i < (row*column); i++)
		new_Matrix.array[i] = this->array[i] - add_matrix.array[i];
	return new_Matrix;
}

//==================================================================================

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>&			Matrix<T,row,column>::	multiplicate			(const Matrix& multrix)
{
	std::array<T,row*column> new_array;
	new_array.fill(0.f);

	for	(unsigned int i = 0; i < row; i++)
	{
		for (unsigned int j = 0; j < column; j++)
		{
			for (unsigned int k = 0; k < row; k++)
			{
				new_array[(i*column)+j] += this->array[(i * column) + k] * multrix.array[(k * column) + j];		
			}
		}
	}
	this->array = new_array;
	return *this;
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>		Matrix<T,row,column>::		multiplicate	(T scalar)const
{
	Matrix<T,row,column> new_Matrix; 

	for (unsigned int i = 0; i < (row*column); i++)
		new_Matrix.array[i] = this->array[i] * scalar;
	return new_Matrix;
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>&		Matrix<T,row,column>::	multiplicate	(T scalar)
{
	for (unsigned int i = 0; i < (row*column); i++)
		this->array[i] = this->array[i] * scalar;
	return *this;

}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>		Matrix<T,row,column>::	divide			(T scalar)const
{
	Matrix<T,row,column> new_Matrix; 

	for (unsigned int i = 0; i < (row*column); i++)
		new_Matrix.array[i] = this->array[i] / scalar;
	return new_Matrix;
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>&		Matrix<T,row,column>::	divide			(T scalar)
{
	for (unsigned int i = 0; i < (row*column); i++)
		this->array[i] = this->array[i] / scalar;
	return *this;
}
//==================================================================================

template<typename T, unsigned int row, unsigned int column>
inline T					Matrix<T,row,column>::	getMinor		(unsigned int i, unsigned int j)const
{
	return GetSubMatrix(*this,j,i).det();
}

template<typename T, unsigned int row, unsigned int column>
inline T					Matrix<T,row,column>::	getCofactor		(unsigned int i, unsigned int j)const
{
	return powf(-1,i+j) * getMinor(i,j);
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>		Matrix<T,row,column>::	getComatrix		()const
{
	Matrix<T,row,column> CoMatrix;

	for (unsigned int i = 0; i < row; i++)
	{
		for (unsigned int j = 0; j < column; j++)
		{
			CoMatrix[i][j] = getCofactor(i,j);
		}
	}
	return CoMatrix;
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>		Matrix<T,row,column>::	getConjugateMatrix	()const
{
	return getComatrix().transponate();
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>		Matrix<T,row,column>::	getInverseMatrix	()const
{
	T det = this->det();

	if (det == 0)
		return Matrix<T,row,column>::zero();
	else
	{
		return (getConjugateMatrix() / det);
	}
}



//==================================================================================

template<typename T, unsigned int row, unsigned int column>
inline T*			Matrix<T,row,column>::	operator[]		(unsigned int u)
{
	return &this->array[u * column];
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>&			Matrix<T,row,column>::	operator+=			(const Matrix& add_matrix)
{
	return this->add(add_matrix);
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>			Matrix<T,row,column>::	operator+			(const Matrix& add_matrix)const
{
	return this->add(add_matrix);
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>&			Matrix<T,row,column>::	operator-=			(const Matrix& add_matrix)
{
	return this->substract(add_matrix);
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>			Matrix<T,row,column>::	operator-			(const Matrix& add_matrix)const
{
	return this->substract(add_matrix);
}


template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>&			Matrix<T,row,column>::	operator*=			(const Matrix& multrix)
{
	return this->multiplicate(multrix);
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>			Matrix<T,row,column>::	operator*			(T scalar)const
{
	return this->multiplicate(scalar);
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>&			Matrix<T,row,column>::	operator*=			(T scalar)
{
	return this->multiplicate(scalar);
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>			Matrix<T,row,column>::	operator/			(T scalar)const
{
	return this->divide(scalar);
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>&			Matrix<T,row,column>::	operator/=			(T scalar)
{
	return this->divide(scalar);
}

template<typename T, unsigned int row, unsigned int column>
inline Matrix<T,row,column>			Matrix<T,row,column>::		operator*			(const Matrix<T,row,column>& multrix)const
{
	return multiplicate(multrix);
}

//==================================================================================
template<typename T, unsigned int row, unsigned int column>
inline void			Matrix<T,row,column>::	display			()const
{
	for (unsigned int i = 0; i < row; i++)
	{

			for (unsigned int k = 0; k < column ; k++)
				std::cout << "==-";
			std::cout << std::endl << "|";

		for (unsigned int j = 0; j < column; j++)
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

#endif //__MATRIX_INL__
