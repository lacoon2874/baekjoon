#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, x, temp;

	std::cin >> n >> x;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		if (temp < x) {
			std::cout << temp << ' ';
		}
	}

	return 0;
}