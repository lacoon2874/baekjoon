#include <iostream>
#include <string>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t;
	std::string str;

	std::cin >> t;
	int score, sum;
	for (int i = 0; i < t; i++) {
		score = 0;
		sum = 0;
		std::cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'O') {
				score++;
				sum += score;
			}
			else {
				score = 0;
			}
		}
		std::cout << sum << '\n';
	}

	return 0;
}