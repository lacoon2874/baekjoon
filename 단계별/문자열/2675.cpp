#include <iostream>
#include <string>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t, r;
	std::string str;

	std::cin >> t;
	for (int i = 0; i < t; i++) {
		std::cin >> r >> str;
		for (int j = 0; j < str.length(); j++) {
			for (int k = 0; k < r; k++) {
				std::cout << str[j];
			}
		}
		std::cout << '\n';
	}

	return 0;
}