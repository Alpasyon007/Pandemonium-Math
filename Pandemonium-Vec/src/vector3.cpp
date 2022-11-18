#include "ppch.h"
#include "vector3.h"

namespace Pandemonium {
	namespace Math {
		namespace Vector {
			// Vector3
			// Constructor
			Vector3::Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
			Vector3::Vector3(float _x, float _y) : x(_x), y(_y), z(0) {}
			Vector3::Vector3() : x(0), y(0), z(0) {}

			// Operators
			// Equals
			void Vector3::operator=(Vector3 const& v) {
				x = v.x;
				y = v.y;
				z = v.z;
			};
			bool Vector3::operator==(Vector3 const& v) { return x == v.x && y == v.y && z == v.z; }

			// Addition
			Vector3 Vector3::operator+(Vector3 const& v) { return Vector3(x + v.x, y + v.y, z + v.z); };
			void Vector3::operator+=(Vector3 const& v) {
				x += v.x;
				y += v.y;
				z += v.z;
			};

			// Subbtraction
			Vector3 Vector3::operator-(Vector3 const& v) { return Vector3(x - v.x, y - v.y, z - v.z); };
			void Vector3::operator-=(Vector3 const& v) {
				x -= v.x;
				y -= v.y;
				z -= v.z;
			};

			// Multiplication
			Vector3 Vector3::operator*(int const& n) { return Vector3(x * n, y * n, z * n); };
			void Vector3::operator*=(int const& n) {
				x *= n;
				y *= n;
				z *= n;
			};

			// Multiplication
			Vector3 Vector3::operator/(int const& n) { return Vector3(x / n, y / n, z / n); };
			void Vector3::operator/=(int const& n) {
				x /= n;
				y /= n;
				z /= n;
			};

			// Methods
			void Vector3::Inverse() {
				x = -x;
				y = -y;
				z = -z;
			}

			float	Vector3::Dot(Vector3 const& v) { return ((x * v.x) + (y * v.y) + (z * v.z)); }

			float	Vector3::Magnitude() { return std::sqrt(((x * x) + (y * y) + (z * z))); }

			float	Vector3::Distance(Vector3 const& v) { return (*this - v).Magnitude(); }

			Vector3 Vector3::Cross(const Vector3& v) { return Vector3(((y * v.z) - (z * v.y)), ((z * v.x) - (x * v.z)), ((x * v.y) - (y * v.x))); }

			Vector3 Vector3::Normalised() {
				const float magnitude = this->Magnitude();
				return Vector3(x / magnitude, y / magnitude, z / magnitude);
			}

		} // namespace Vector
	}	  // namespace Math
} // namespace Pandemonium