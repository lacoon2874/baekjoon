#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t, h, w, n;

	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> h >> w >> n;
		std::cout << ((n - 1) % h + 1);
		std::cout.width(2);
		std::cout.fill('0');
		std::cout << ((n - 1) / h) + 1;
		std::cout << '\n';
	}

	return 0;
}