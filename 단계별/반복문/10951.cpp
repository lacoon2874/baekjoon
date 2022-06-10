#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int a, b;

	std::cin >> a >> b;
	while (!std::cin.eof()) {
		std::cout << a + b << '\n';
		std::cin >> a >> b;
	}

	return 0;
}