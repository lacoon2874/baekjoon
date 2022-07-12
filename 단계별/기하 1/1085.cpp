#include <iostream>

int min(int, int);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int x, y, w, h;
	std::cin >> x >> y >> w >> h;

	std::cout << min(min(x, w - x), min(y, h - y));

	return 0;
}

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	else {
		return b;
	}
}