#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	int* arr = new int[10001];
	
	for (int i = 1; i < 10001; i++) {
		arr[i] = 0;
	}
	std::cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		arr[temp]++;
	}
	for (int i = 1; i < 10001; i++) {
		for (int j = 0; j < arr[i]; j++) {
			std::cout << i << '\n';
		}
	}

	delete[] arr;

	return 0;
}