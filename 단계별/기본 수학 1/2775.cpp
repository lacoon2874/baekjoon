#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t, k, n;
	long long answer;

	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> k >> n;
		answer = 1;
		if (k + 1 < n - 1) {
			for (int j = k + n; j > n - 1; j--) {
				answer *= j;
			}
			for (int j = 2; j <= k + 1; j++) {
				answer /= j;
			}
		}
		else {
			for (int j = k + n; j > k + 1; j--) {
				answer *= j;
			}
			for (int j = 2; j <= n - 1; j++) {
				answer /= j;
			}
		}
		std::cout << answer << '\n';
	}

	return 0;
}