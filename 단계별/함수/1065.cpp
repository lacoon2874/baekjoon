#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	std::cin >> n;
	int dif, count = 0;
	bool isTrue;
	for (int i = 1; i <= n; i++) {
		isTrue = true;
		dif = (i % 100) / 10 - i % 10;
		for (int j = i / 10; j > 9; j /= 10) {
			if (dif != (j % 100) / 10 - j % 10) {
				isTrue = false;
				break;
			}
		}
		if (isTrue) {
			count++;
		}
	}
	std::cout << count;

	return 0;
}