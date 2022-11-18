#ifndef VECTOR3_H
#define VECTOR3_H

namespace Pandemonium {
	namespace Math {
		namespace Vector {
			class Vector3 {
				// Variables
			private:
			public:
				float x;
				float y;
				float z;
				// Methods
			private:
			public:
				// Constructors
				Vector3(float _x, float _y, float _z);
				Vector3(float _x, float _y);
				Vector3();

				// Operators
				void	operator=(Vector3 const& v);
				bool	operator==(Vector3 const& v);

				Vector3 operator+(Vector3 const& v);
				void	operator+=(Vector3 const& v);

				Vector3 operator-(Vector3 const& v);
				void	operator-=(Vector3 const& v);

				Vector3 operator*(int const& n);
				void	operator*=(int const& n);

				Vector3 operator/(int const& n);
				void	operator/=(int const& n);

				// Methods
				void	Inverse();
				float	Magnitude();
				float	Distance(Vector3 const& v);
				float	Dot(Vector3 const& v);
				Vector3 Normalised();
				Vector3 Cross(Vector3 const& v);
			};
		} // namespace Vector
	}	  // namespace Math
} // namespace Pandemonium

#endif /* VECTOR3_H */