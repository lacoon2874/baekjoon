#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, sum;
	int answer = 0;

	std::cin >> n;
	for (int i = 1; i < n; i++) {
		sum = i;
		for (int j = i; j; j /= 10) {
			sum += j % 10;
		}
		if (sum == n) {
			answer = i;
			break;
		}
	}
	std::cout << answer;

	return 0;
}