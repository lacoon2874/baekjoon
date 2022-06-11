#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, max = 0;
	double temp, sum = 0;

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		sum += temp;
		if (temp > max) {
			max = temp;
		}
	}
	std::cout << std::fixed;
	std::cout.precision(2);
	std::cout << sum / n / max * 100;

	return 0;
}