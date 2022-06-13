#include <iostream>
#include <string>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::string str;
	bool alpha[26];
	bool isGroup;
	int n, count = 0;
	char before;
	
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 26; j++) {
			alpha[j] = false;
		}
		isGroup = true;
		before = 'a' - 1;
		std::cin >> str;
		for (int j = 0; j < str.length(); j++) {
			if (str[j] != before) {
				if (alpha[str[j] - 'a']) {
					isGroup = false;
					break;
				}
				alpha[str[j] - 'a'] = true;
			}
			before = str[j];
		}
		if (isGroup) {
			count++;
		}
	}
	std::cout << count;

	return 0;
}