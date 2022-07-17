#include <iostream>
#include <cmath>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;
	for (int testcase = 1; testcase <= t; testcase++) {
		int startX, startY, finishX, finishY;
		std::cin >> startX >> startY >> finishX >> finishY;
		int n;
		std::cin >> n;
		int count = 0;
		for (int i = 0; i < n; i++) {
			int x, y, r;
			std::cin >> x >> y >> r;
			double distance1 = sqrt(pow(x - startX, 2) + pow(y - startY, 2));
			double distance2 = sqrt(pow(x - finishX, 2) + pow(y - finishY, 2));
			if ((distance1 < r && distance2 > r) || (distance1 > r && distance2 < r)) {
				count++;
			}
		}
		std::cout << count << '\n';
	}

	return 0;
}