#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	bool arr[10001];
	int sum;

	for (int i = 1; i <= 10000; i++) {
		arr[i] = false;
	}
	for (int i = 1; i <= 10000; i++) {
		sum = i;
		for (int j = i; j;) {
			sum += (j % 10);
			j /= 10;
		}
		if (sum <= 10000) {
			arr[sum] = true;
		}
	}
	for (int i = 1; i <= 10000; i++) {
		if (!arr[i]) {
			std::cout << i << '\n';
		}
	}

	return 0;
}