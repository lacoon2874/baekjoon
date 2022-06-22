#include <iostream>
#include <cmath>

void printSq(int*, const int, const int*);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	
	std::cin >> n;
	std::cout << (int)pow(2, n) - 1 << '\n';

	int* pos = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		pos[i] = 1;
	}
	int dif[2];
	if (n % 2) {
		dif[0] = 1;
		dif[1] = 2;
	}
	else {
		dif[0] = 2;
		dif[1] = 1;
	}

	printSq(pos, n, dif);

	delete[] pos;

	return 0;
}

void printSq(int* pos, const int cur, const int* dif) {
	if (cur < 1) {
		return;
	}
	
	printSq(pos, cur - 1, dif);

	std::cout << pos[cur] << ' ';
	pos[cur] = pos[cur] + dif[cur % 2];
	if (pos[cur] > 3) {
		pos[cur] -= 3;
	}
	std::cout << pos[cur] << '\n';
	
	printSq(pos, cur - 1, dif);
}