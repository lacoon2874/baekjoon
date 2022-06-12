#include <iostream>
#include <string>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, sum = 0;
	std::string str;
	std::cin >> n >> str;
	for (int i = 0; i < n; i++) {
		sum += (str[i] - '0');
	}
	std::cout << sum;

	return 0;
}