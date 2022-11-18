#ifndef MATRIX4x4_H
#define MATRIX4x4_H

#include "ppch.h"

namespace Pandemonium {
	namespace Math {
		namespace Matrix {
			class Matrix4x4 {
				// Variables
			private:
			public:
				float mat[4][4];
				// Methods
			private:
			public:
				// Constructors
				Matrix4x4(float arr[4][4]);
				Matrix4x4(std::initializer_list<std::initializer_list<float>> arr);
				Matrix4x4();

				// Operators
				void								operator=(Matrix4x4 const& v);
				bool								operator==(Matrix4x4 const& v);

				Matrix4x4							operator+(Matrix4x4 const& v);
				void								operator+=(Matrix4x4 const& v);

				Matrix4x4							operator-(Matrix4x4 const& v);
				void								operator-=(Matrix4x4 const& v);

				Matrix4x4							operator*(int const& n);
				void								operator*=(int const& n);

				Matrix4x4							operator/(int const& n);
				void								operator/=(int const& n);

				// Methods
				static Matrix4x4					Identity();
				std::array<std::array<float, 4>, 4> Get();
				void								Invert();
				// void	Rotate		(float const &ang);
				// void	RotateRad	(float const &ang);
				// float	Magnitude	();
				// float	Distance	(Matrix4x4 const &v);
				// float	Dot			(Matrix4x4 const &v);
				// Matrix4x4	Normalised	();

				// Debug
				void								Print();
			};
		} // namespace Matrix
	}	  // namespace Math
} // namespace Pandemonium

#endif /* MATRIX4x4_H */