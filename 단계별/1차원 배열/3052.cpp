#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int temp;
	bool arr[42];

	for (int i = 0; i < 42; i++) {
		arr[i] = false;
	}
	for (int i = 0; i < 10; i++) {
		std::cin >> temp;
		arr[temp % 42] = true;
	}
	int count = 0;
	for (int i = 0; i < 42; i++) {
		if (arr[i]) {
			count++;
		}
	}
	std::cout << count;

	return 0;
}