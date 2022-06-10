#include <iostream>

int main(void) {
	int a, b;

	std::cin >> a >> b;
	if (b < 45) {
		std::cout << (a + 23) % 24;
	}
	else {
		std::cout << a;
	}
	std::cout << " " << (b + 15) % 60;

	return 0;
}