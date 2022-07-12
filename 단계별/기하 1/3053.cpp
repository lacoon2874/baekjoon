#include <iostream>
#include <cmath>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	const double pi = std::acos(-1);
	int r;
	
	std::cin >> r;
	std::cout << std::fixed;
	std::cout.precision(5);
	std::cout << r * r * pi << '\n';
	std::cout << 2 * r * r << '\n';

	return 0;
}