#include <iostream>
#include "math.h"

using namespace Pandemonium::Math::Vector;
using namespace Pandemonium::Math::Matrix;

int main() {
	Vector2 Vec2(3, 3);
	Vector2 Vec22(6, 6);
	
	std::cout << Vec2.Distance(Vec22) << std::endl;

	Matrix4x4 test = Matrix4x4::Identity();
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << test.Get()[i][j] << " ";
		}
		std::cout << std::endl;
	}
}