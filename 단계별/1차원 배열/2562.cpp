#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int temp, max = 0, maxIdx;

	for (int i = 1; i <= 9; i++) {
		std::cin >> temp;
		if (temp > max) {
			max = temp;
			maxIdx = i;
		}
	}
	std::cout << max << '\n' << maxIdx;

	return 0;
}