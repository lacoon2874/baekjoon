#include <iostream>
#include <string>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::string str;
	int time = 0;

	std::cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] <= 'O') {
			time += (str[i] - 'A') / 3 + 3;
		}
		else if (str[i] <= 'S') {
			time += 8;
		}
		else if (str[i] <= 'V') {
			time += 9;
		}
		else {
			time += 10;
		}
	}
	std::cout << time;

	return 0;
}