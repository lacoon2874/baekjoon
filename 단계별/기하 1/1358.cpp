#include <iostream>
#include <cmath>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int w, h, x, y, p;
	std::cin >> w >> h >> x >> y >> p;
	int count = 0;
	for (int i = 0; i < p; i++) {
		int a, b;
		std::cin >> a >> b;
		if ((a >= x && a <= x + w && b >= y && b <= y + h) || (sqrt(pow(a - x, 2) + pow(b - y - h / 2, 2)) <= h / 2) || (sqrt(pow(a - x - w, 2) + pow(b - y - h / 2, 2)) <= h / 2)) {
			count++;
		}
	}
	std::cout << count << '\n';

	return 0;
}