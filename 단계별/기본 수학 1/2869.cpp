#include <iostream>
#include <cmath>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int a, b, v;

	std::cin >> a >> b >> v;
	if ((v - a) % (a - b)) {
		std::cout << (v - a) / (a - b) + 2;
	}
	else {
		std::cout << (v - a) / (a - b) + 1;
	}

	return 0;
}