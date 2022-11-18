#include "matrix4x4.h"

#include <cmath>
#include <iostream>

namespace Pandemonium {
	namespace Math {
		namespace Matrix {
			// Matrix4x4
			// // Constructor
			Matrix4x4::Matrix4x4(std::initializer_list<std::initializer_list<float>> arr)
				: mat{{arr.begin()[0].begin()[0], arr.begin()[0].begin()[1], arr.begin()[0].begin()[2], arr.begin()[0].begin()[3]},
					  {arr.begin()[1].begin()[0], arr.begin()[1].begin()[1], arr.begin()[1].begin()[2], arr.begin()[1].begin()[3]},
					  {arr.begin()[2].begin()[0], arr.begin()[2].begin()[1], arr.begin()[2].begin()[2], arr.begin()[2].begin()[3]},
					  {arr.begin()[3].begin()[0], arr.begin()[3].begin()[1], arr.begin()[3].begin()[2], arr.begin()[3].begin()[3]}} {}

			Matrix4x4::Matrix4x4(float arr[4][4])
				: mat{{arr[0][0], arr[0][1], arr[0][2], arr[0][3]},
					  {arr[1][0], arr[1][1], arr[1][2], arr[1][3]},
					  {arr[2][0], arr[2][1], arr[2][2], arr[2][3]},
					  {arr[3][0], arr[3][1], arr[3][2], arr[3][3]}} {}

			Matrix4x4::Matrix4x4() : mat{{0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 0.0f}} {};

			// // Operators
			// // Equals
			// void	Matrix4x4::operator=		(Matrix4x4 const &v)		{ x = v.x, y = v.y; }
			// bool	Matrix4x4::operator==		(Matrix4x4 const &v)		{ return x == v.x && y == v.y; }

			// // Addition
			// Matrix4x4	Matrix4x4::operator+		(Matrix4x4 const &v)		{ return Matrix4x4(x + v.x, y + v.y); }
			// void	Matrix4x4::operator+=		(Matrix4x4 const &v)		{ x += v.x; y += v.y; }

			// // Subttraction
			// Matrix4x4	Matrix4x4::operator-		(Matrix4x4 const &v)		{ return Matrix4x4(x - v.x, y - v.y); }
			// void	Matrix4x4::operator-=		(Matrix4x4 const &v)		{ x -= v.x; y -= v.y; }

			// // Multiplication
			// Matrix4x4	Matrix4x4::operator*		(int const &n)			{ return Matrix4x4(x * n, y * n); }
			// void	Matrix4x4::operator*=		(int const &n)			{ x *= n; y *=n; }

			// // Multiplication
			// Matrix4x4	Matrix4x4::operator/		(int const &n)			{ return Matrix4x4(x / n, y / n); }
			// void	Matrix4x4::operator/=		(int const &n)			{ x /= n; y /=n; }

			// Methods
			// void	Matrix4x4::Inverse		()						{ x = -x; y = -y; }

			// void	Matrix4x4::Rotate			(const float &ang)		{ RotateRad(((180 * ang) / M_PI)); }

			// float	Matrix4x4::Dot			(Matrix4x4 const &v)		{ return ((x * v.x) + (y * v.y)); }

			// float	Matrix4x4::Magnitude		()						{ return std::sqrt(((x * x) + (y * y))); }

			// float	Matrix4x4::Distance		(Matrix4x4 const &v)		{ return (*this - v).Magnitude(); }

			// void	Matrix4x4::RotateRad		(const float &ang)		{
			// 	// Current x, y
			// 	const float x_i = x;
			// 	const float y_i = y;

			// 	// Current Angle cos, sin
			// 	const float angCos = std::cos(ang);
			// 	const float angSin = std::sin(ang);

			// 	// Rotation
			// 	x = (x_i * angCos) - (y_i * angSin);
			// 	y = (x_i * angSin) + (y_i * angCos);
			// }

			// Matrix4x4	Matrix4x4::Normalised		()						{
			// 	const float magnitude = this->Magnitude();
			// 	return Matrix4x4(x / magnitude, y / magnitude);
			// }

			std::array<std::array<float, 4>, 4> Matrix4x4::Get() { return reinterpret_cast<std::array<std::array<float, 4>, 4>&>(mat); };

			Matrix4x4 Matrix4x4::Identity() { return {{1.0f, 0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}}; }

			void	  Matrix4x4::Invert() {
				 Matrix4x4 temp(mat);

				 // Cache the matrix values (speed optimization)
				 // float a00 = mat.m0, a01 = mat.m1, a02 = mat.m2, a03 = mat.m3;
				 // float a10 = mat.m4, a11 = mat.m5, a12 = mat.m6, a13 = mat.m7;
				 // float a20 = mat.m8, a21 = mat.m9, a22 = mat.m10, a23 = mat.m11;
				 // float a30 = mat.m12, a31 = mat.m13, a32 = mat.m14, a33 = mat.m15;

				 // float b00 = a00*a11 - a01*a10;
				 // float b01 = a00*a12 - a02*a10;
				 // float b02 = a00*a13 - a03*a10;
				 // float b03 = a01*a12 - a02*a11;
				 // float b04 = a01*a13 - a03*a11;
				 // float b05 = a02*a13 - a03*a12;
				 // float b06 = a20*a31 - a21*a30;
				 // float b07 = a20*a32 - a22*a30;
				 // float b08 = a20*a33 - a23*a30;
				 // float b09 = a21*a32 - a22*a31;
				 // float b10 = a21*a33 - a23*a31;
				 // float b11 = a22*a33 - a23*a32;

				 // Calculate the invert determinant (inlined to avoid double-caching)
				 // float invDet = 1.0f/(b00*b11 - b01*b10 + b02*b09 + b03*b08 - b04*b07 + b05*b06);

				 // result.m0 = (a11*b11 - a12*b10 + a13*b09)*invDet;
				 // result.m1 = (-a01*b11 + a02*b10 - a03*b09)*invDet;
				 // result.m2 = (a31*b05 - a32*b04 + a33*b03)*invDet;
				 // result.m3 = (-a21*b05 + a22*b04 - a23*b03)*invDet;
				 // result.m4 = (-a10*b11 + a12*b08 - a13*b07)*invDet;
				 // result.m5 = (a00*b11 - a02*b08 + a03*b07)*invDet;
				 // result.m6 = (-a30*b05 + a32*b02 - a33*b01)*invDet;
				 // result.m7 = (a20*b05 - a22*b02 + a23*b01)*invDet;
				 // result.m8 = (a10*b10 - a11*b08 + a13*b06)*invDet;
				 // result.m9 = (-a00*b10 + a01*b08 - a03*b06)*invDet;
				 // result.m10 = (a30*b04 - a31*b02 + a33*b00)*invDet;
				 // result.m11 = (-a20*b04 + a21*b02 - a23*b00)*invDet;
				 // result.m12 = (-a10*b09 + a11*b07 - a12*b06)*invDet;
				 // result.m13 = (a00*b09 - a01*b07 + a02*b06)*invDet;
				 // result.m14 = (-a30*b03 + a31*b01 - a32*b00)*invDet;
				 // result.m15 = (a20*b03 - a21*b01 + a22*b00)*invDet;

				 // return result;
			}

			void Matrix4x4::Print() {
				for(int i = 0; i < 4; i++) {
					for(int j = 0; j < 4; j++) {
						std::cout << mat[i][j] << " ";
					}
					std::cout << std::endl;
				}
			}
		} // namespace Matrix
	}	  // namespace Math
} // namespace Pandemonium