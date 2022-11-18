#ifndef VECTOR2_H
#define VECTOR2_H

namespace Pandemonium {
	namespace Math {
		namespace Vector {
			class Vector2 {
				// Variables
			private:
			public:
				float x;
				float y;
				// Methods
			private:
			public:
				// Constructors
				Vector2(float _x, float _y);
				Vector2();

				// Operators
				void	operator=(Vector2 const& v);
				bool	operator==(Vector2 const& v);

				Vector2 operator+(Vector2 const& v);
				void	operator+=(Vector2 const& v);

				Vector2 operator-(Vector2 const& v);
				void	operator-=(Vector2 const& v);

				Vector2 operator*(int const& n);
				void	operator*=(int const& n);

				Vector2 operator/(int const& n);
				void	operator/=(int const& n);

				// Methods
				void	Inverse();
				void	Rotate(float const& ang);
				void	RotateRad(float const& ang);
				float	Magnitude();
				float	Distance(Vector2 const& v);
				float	Dot(Vector2 const& v);
				Vector2 Normalised();
			};
		} // namespace Vector
	}	  // namespace Math
} // namespace Pandemonium

#endif /* VECTOR2_H */