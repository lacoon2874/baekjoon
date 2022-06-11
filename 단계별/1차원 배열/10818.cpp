#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, min = 1000001, max = -1000001;

	std::cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		if (temp < min) {
			min = temp;
		}
		if (temp > max) {
			max = temp;
		}
	}
	std::cout << min << ' ' << max;

	return 0;
}