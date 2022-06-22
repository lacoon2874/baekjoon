#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	const int maxSize = 246913;
	int* prime = new int[maxSize];
	
	prime[1] = 0;
	for (int i = 2; i < maxSize; i++) {
		prime[i] = 1;
	}
	for (int i = 2; i < maxSize / 2; i++) {
		if (prime[i]) {
			for (int j = 2; j * i < maxSize; j++) {
				prime[j * i] = 0;
			}
		}
	}
	for (int i = 3; i < maxSize; i++) {
		prime[i] += prime[i - 1];
	}
	
	int n;
	std::cin >> n;
	while (n) {
		std::cout << prime[2 * n] - prime[n] << '\n';
		std::cin >> n;
	}

	delete[] prime;

	return 0;
}