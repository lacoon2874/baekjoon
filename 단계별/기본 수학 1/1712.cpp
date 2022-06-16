#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int a, b, c;
	
	std::cin >> a >> b >> c;
	if (b >= c) {
		std::cout << -1;
	}
	else {
		std::cout << a / (c - b) + 1;
	}

	return 0;
}