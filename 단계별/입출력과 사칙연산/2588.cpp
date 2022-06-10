#include <iostream>

int main(void) {
	int a, b, temp;

	std::cin >> a >> b;
	temp = b;
	for (int i = 0; i < 3; i++) {
		std::cout << a * (temp % 10) << std::endl;
		temp /= 10;
	}
	std::cout << a * b << std::endl;

	return 0;
}