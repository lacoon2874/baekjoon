#include <iostream>

int main(void) {
	int a, b, c;

	std::cin >> a >> b >> c;
	std::cout << (a + ((b + c) / 60)) % 24;
	std::cout << " " << (b + c) % 60;

	return 0;
}