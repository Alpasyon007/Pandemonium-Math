#include "ppch.h"
#include "math_consts.h"
#include "vector2.h"

namespace Pandemonium {
	namespace Math {
		namespace Vector {
			// Vector2
			// Constructor
			Vector2::Vector2(float _x, float _y) : x(_x), y(_y) {}

			Vector2::Vector2() : x(0), y(0){};

			// Operators
			// Equals
			void Vector2::operator=(Vector2 const& v) { x = v.x, y = v.y; }

			bool Vector2::operator==(Vector2 const& v) { return x == v.x && y == v.y; }

			// Addition
			Vector2 Vector2::operator+(Vector2 const& v) { return Vector2(x + v.x, y + v.y); }

			void Vector2::operator+=(Vector2 const& v) {
				x += v.x;
				y += v.y;
			}

			// Subttraction
			Vector2 Vector2::operator-(Vector2 const& v) { return Vector2(x - v.x, y - v.y); }

			void Vector2::operator-=(Vector2 const& v) {
				x -= v.x;
				y -= v.y;
			}

			// Multiplication
			Vector2 Vector2::operator*(int const& n) { return Vector2(x * n, y * n); }

			void Vector2::operator*=(int const& n) {
				x *= n;
				y *= n;
			}

			// Multiplication
			Vector2 Vector2::operator/(int const& n) { return Vector2(x / n, y / n); }

			void Vector2::operator/=(int const& n) {
				x /= n;
				y /= n;
			}

			// Methods
			void Vector2::Inverse() {
				x = -x;
				y = -y;
			}

			void  Vector2::Rotate(const float& ang) { RotateRad(static_cast<float>((180 * ang) / M_PI)); }

			float Vector2::Dot(Vector2 const& v) { return ((x * v.x) + (y * v.y)); }

			float Vector2::Magnitude() { return std::sqrt(((x * x) + (y * y))); }

			float Vector2::Distance(Vector2 const& v) { return (*this - v).Magnitude(); }

			void  Vector2::RotateRad(const float& ang) {
				 // Current x, y
				 const float x_i	= x;
				 const float y_i	= y;

				 // Current Angle cos, sin
				 const float angCos = std::cos(ang);
				 const float angSin = std::sin(ang);

				 // Rotation
				 x					= (x_i * angCos) - (y_i * angSin);
				 y					= (x_i * angSin) + (y_i * angCos);
			 }

			Vector2 Vector2::Normalised() {
				const float magnitude = this->Magnitude();
				return Vector2(x / magnitude, y / magnitude);
			}
		} // namespace Vector
	}	  // namespace Math
} // namespace Pandemonium