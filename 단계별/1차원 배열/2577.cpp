#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int a, b, c;
	int arr[10];

	for (int i = 0; i < 10; i++) {
		arr[i] = 0;
	}
	std::cin >> a >> b >> c;
	int result = a * b * c;
	while (result) {
		arr[result % 10]++;
		result /= 10;
	}
	for (int i = 0; i < 10; i++) {
		std::cout << arr[i] << '\n';
	}

	return 0;
}