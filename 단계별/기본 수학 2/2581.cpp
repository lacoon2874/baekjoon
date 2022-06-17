#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int m, n, min, sum = 0;

	std::cin >> m >> n;
	for (int i = n; i >= m; i--) {
		int j;
		for (j = 2; j < 101 && j < i; j++) {
			if (!(i % j)) {
				break;
			}
		}
		if (j == 101 || j == i) {
			sum += i;
			min = i;
		}
	}
	if (sum == 0) {
		std::cout << -1;
	}
	else {
		std::cout << sum << '\n' << min;
	}

	return 0;
}