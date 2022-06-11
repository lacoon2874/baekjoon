#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int c, n;
	int arr[1000];

	std::cout << std::fixed;
	std::cout.precision(3);
	std::cin >> c;
	double sum, count;
	for (int i = 0; i < c; i++) {
		std::cin >> n;
		sum = 0;
		for (int j = 0; j < n; j++) {
			std::cin >> arr[j];
			sum += arr[j];
		}
		sum /= n;
		count = 0;
		for (int j = 0; j < n; j++) {
			if (arr[j] > sum) {
				count++;
			}
		}
		std::cout << count / n * 100 << "%\n";
	}

	return 0;
}