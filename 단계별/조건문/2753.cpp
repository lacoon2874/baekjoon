#include <iostream>

int main(void) {
	int a;

	std::cin >> a;
	if (!(a % 400)) {
		std::cout << '1';
	}
	else if (!(a % 100)) {
		std::cout << '0';
	}
	else if (!(a % 4)) {
		std::cout << '1';
	}
	else {
		std::cout << '0';
	}

	return 0;
}