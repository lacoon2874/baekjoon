#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, num, answer = 0;

	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> num;

		int j;
		for (j = 2; j < num; j++) {
			if (!(num % j)) {
				break;
			}
		}
		if (j == num) {
			answer++;
		}
	}
	std::cout << answer;
	
	return 0;
}