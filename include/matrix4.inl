#ifndef __MATRIX4_INL__
#define __MATRIX4_INL__

#include "matrix.h"

//=================================================================================

template<typename T>
Matrix4<T>::			Matrix4			():
	Matrix<T,4,4>()
{
}

template<typename T>
Matrix4<T>::			Matrix4			(const Matrix<T,4,4>& CopyMatrix):
	Matrix<T,4,4>(CopyMatrix)
{
}

template<typename T>
Matrix4<T>::			Matrix4			(const Matrix4<T>& CopyMatrix4):
	Matrix<T,4,4>(CopyMatrix4)
{
}

template<typename T>
Matrix4<T>::			~Matrix4				()
{
}

//=================================================================================

template<typename T>
inline Matrix4<T>			Matrix4<T>::	identity		()
{
	return Matrix<T,4,4>::identity();
}

template<typename T>
inline Matrix4<T>			Matrix4<T>::	zero			()
{
	return Matrix<T,4,4>::zero();
}

//=================================================================================

template<typename T>
inline Matrix4<T>			Matrix4<T>::			CreateScaleMatrix 		(const Vec3& scale)
{
	Matrix4<T> ScaleMatrix (Matrix4<T>::identity());

	ScaleMatrix[0][0] = scale.x;
	ScaleMatrix[1][1] = scale.y;
	ScaleMatrix[2][2] = scale.z;

	return ScaleMatrix;
}

template<typename T>
inline Matrix4<T>			Matrix4<T>::			CreateTranslationMatrix (const Vec3& translate)
{
	Matrix4<T> TranslationMatrix (Matrix4<T>::identity());

	TranslationMatrix[0][3] = translate.x;
	TranslationMatrix[1][3] = translate.y;
	TranslationMatrix[2][3] = translate.z;

	return TranslationMatrix;
}

template<typename T>
inline Matrix4<T>			Matrix4<T>::			CreateFixedAngleEulerRotationMatrix (const Vec3& rotation)
{
	return(	CreateYRotationMatrix(degrees_to_radian(rotation.y)) *=
			CreateXRotationMatrix(degrees_to_radian(rotation.x)) *= 
			CreateZRotationMatrix(degrees_to_radian(rotation.z)));
}

template<typename T>
inline Matrix4<T>			Matrix4<T>::			CreateTRSMatrix			(const Vec3& scale, const Vec3& rotation, const Vec3& translation)
{
	return(CreateTranslationMatrix(translation) *= CreateFixedAngleEulerRotationMatrix(rotation) *= CreateScaleMatrix(scale));
}

//=================================================================================

template<typename T>
inline Matrix4<T>			Matrix4<T>::			CreateXRotationMatrix	 (const float& angleX)
{
	Matrix4<T> XRotationMatrix (Matrix4<T>::identity());

	XRotationMatrix[1][1] = cosf(angleX);
	XRotationMatrix[1][2] = -sinf(angleX); 
	XRotationMatrix[2][1] = sinf(angleX);
	XRotationMatrix[2][2] = cosf(angleX); 

	return XRotationMatrix;
}

template<typename T>
inline Matrix4<T>			Matrix4<T>::			CreateYRotationMatrix	 (const float& angleY)
{
	Matrix4<T> YRotationMatrix(Matrix4<T>::identity());

	YRotationMatrix[0][0] = cosf(angleY);
	YRotationMatrix[0][2] = sinf(angleY); 
	YRotationMatrix[2][0] = -sinf(angleY);
	YRotationMatrix[2][2] = cosf(angleY); 

	return YRotationMatrix;
}

template<typename T>
inline Matrix4<T>			Matrix4<T>::			CreateZRotationMatrix	 (const float& angleZ)
{
	Matrix4<T> ZRotationMatrix (Matrix4<T>::identity());

	ZRotationMatrix[0][0] = cosf(angleZ);
	ZRotationMatrix[0][1] = -sinf(angleZ); 
	ZRotationMatrix[1][0] = sinf(angleZ);
	ZRotationMatrix[1][1] = cosf(angleZ); 

	return ZRotationMatrix;
}

template<typename T>
inline Vec4				Matrix4<T>::			multiplicate	(const Vec4& Vector)const
{
	Vec4 MultiVector;

	for (int i = 0; i < 4; i++)
	{
		for (int  k = 0; k < 4; k++)
		{
			MultiVector[i] += this->array[(i * 4) + k] * Vector[k];
		}
	}

	return MultiVector;
}

template<typename T>
inline Vec4				Matrix4<T>::			operator*	(const Vec4& Vector)const
{
	return multiplicate(Vector);
}

template<typename T>
inline Matrix4<T>		Matrix4<T>:: operator*	(const Matrix4<T>& multrix)const
{
	Matrix4<T> new_Matrix;

	for	(unsigned int i = 0; i < 4; i++)
	{
		for (unsigned int j = 0; j < 4 ; j++)
		{
			for (unsigned int k = 0; k < 4 ; k++)
			{
				new_Matrix.array[((i*4)+j)] += this->array[(i * 4) + k] * multrix.array[(k * 4) + j];	
			}
		}
	}
	return new_Matrix;
}



#endif //__MATRIX4_INL__
