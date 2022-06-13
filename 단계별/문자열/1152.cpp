#include <iostream>
#include <string>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::string str;
	int count = 0;
	std::cin >> str;
	while (!std::cin.eof()) {
		count++;
		std::cin >> str;
	}
	std::cout << count;

	return 0;
}