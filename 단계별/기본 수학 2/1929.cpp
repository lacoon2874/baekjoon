#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int m, n;
	bool* prime;

	std::cin >> m >> n;
	prime = new bool[n + 1];

	for (int i = 2; i <= n; i++) {
		prime[i] = true;
	}
	for (int i = 2; i <= n / 2; i++) {
		if (prime[i]) {
			for (int j = 2; j * i <= n; j++) {
				prime[j * i] = false;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (prime[i]) {
			std::cout << i << '\n';
		}
	}

	delete[] prime;

	return 0;
}