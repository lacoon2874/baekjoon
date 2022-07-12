#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int k, temp;
	int len[6];

	std::cin >> k;
	for (int i = 0; i < 6; i++) {
		std::cin >> temp >> len[i];
	}
	int max1 = 0, max2 = 1;
	for (int i = 2; i < 6; i += 2) {
		if (len[i] > len[max1]) {
			max1 = i;
		}
	}
	for (int i = 3; i < 6; i += 2) {
		if (len[i] > len[max2]) {
			max2 = i;
		}
	}
	int min1 = (max1 + 3) % 6;
	int min2 = (max2 + 3) % 6;

	std::cout << (len[max1] * len[max2] - len[min1] * len[min2]) * k;

	return 0;
}