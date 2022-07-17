#include <iostream>
#include <cmath>

struct Pos {
	int x, y, r;
};

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t;
	std::cin >> t;
	Pos pos1, pos2;
	for (int testcase = 1; testcase <= t; testcase++) {
		std::cin >> pos1.x >> pos1.y >> pos1.r;
		std::cin >> pos2.x >> pos2.y >> pos2.r;
		if (pos1.x == pos2.x && pos1.y == pos2.y && pos1.r == pos2.r) {
			std::cout << "-1\n";
		}
		else {
			if (pos2.r > pos1.r) {
				Pos temp = pos1;
				pos1 = pos2;
				pos2 = temp;
			}
			double distance = sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2));
			if (distance > pos1.r + pos2.r) {
				std::cout << "0\n";
			}
			else if (distance == pos1.r + pos2.r) {
				std::cout << "1\n";
			}
			else if (distance == pos1.r - pos2.r) {
				std::cout << "1\n";
			}
			else if (distance < pos1.r - pos2.r) {
				std::cout << "0\n";
			}
			else {
				std::cout << "2\n";
			}
		}
	}

	return 0;
}