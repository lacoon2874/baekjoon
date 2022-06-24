#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;

	std::cin >> n;
	int answer, count;
	for (answer = 666; n; answer++) {
		count = 0;
		for (int j = answer; j; j /= 10) {
			if (j % 10 == 6) {
				count++;
				if (count == 3) {
					n--;
					break;
				}
			}
			else {
				count = 0;
			}
		}
	}
	std::cout << answer - 1;

	return 0;
}