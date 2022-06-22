#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	const int maxSize = 10001;
	bool* prime = new bool[maxSize];

	for (int i = 2; i < maxSize; i++) {
		prime[i] = true;
	}
	for (int i = 2; i < maxSize / 2; i++) {
		if (prime[i]) {
			for (int j = 2; j * i < maxSize; j++) {
				prime[j * i] = false;
			}
		}
	}
	
	int t, n;
	
	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> n;
		for (int j = n / 2; j > 1; j--) {
			if (prime[j] && prime[n - j]) {
				std::cout << j << ' ' << n - j << '\n';
				break;
			}
		}
	}

	delete[] prime;

	return 0;
}