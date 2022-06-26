#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	int arr[10];
	
	for (int i = 0; i < 10; i++) {
		arr[i] = 0;
	}
	std::cin >> n;
	for (; n; n /= 10) {
		arr[n % 10]++;
	}
	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < arr[i]; j++) {
			std::cout << i;
		}
	}

	return 0;
}