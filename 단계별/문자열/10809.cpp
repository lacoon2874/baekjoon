#include <iostream>
#include <string>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int arr[26];
	std::string str;

	for (int i = 0; i < 26; i++) {
		arr[i] = -1;
	}
	std::cin >> str;
	for (int i = str.length() - 1; i >= 0; i--) {
		arr[str[i] - 'a'] = i;
	}
	for (int i = 0; i < 26; i++) {
		std::cout << arr[i] << ' ';
	}

	return 0;
}