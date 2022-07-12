#include <iostream>

struct Pos {
	int x, y;
};

int dif(int, int, int);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	Pos pos[3];
	for (int i = 0; i < 3; i++) {
		std::cin >> pos[i].x >> pos[i].y;
	}
	std::cout << dif(pos[0].x, pos[1].x, pos[2].x) << ' ' << dif(pos[0].y, pos[1].y, pos[2].y);

	return 0;
}

int dif(int a, int b, int c) {
	if (a == b) {
		return c;
	}
	else if (a == c) {
		return b;
	}
	else {
		return a;
	}
}