#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m, max = 0;
	
	std::cin >> n >> m;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int sum = arr[i] + arr[j] + arr[k];
				if (sum <= m && sum > max) {
					max = sum;
				}
			}
		}
	}
	std::cout << max;

	delete[] arr;

	return 0;
}