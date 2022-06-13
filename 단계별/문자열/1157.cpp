#include <iostream>
#include <string>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int arr[26];
	std::string str;

	for (int i = 0; i < 26; i++) {
		arr[i] = 0;
	}
	std::cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a') {
			arr[str[i] - 'a']++;
		}
		else {
			arr[str[i] - 'A']++;
		}
	}
	int max = -1, maxIdx = -1;
	for (int i = 0; i < 26; i++) {
		if (arr[i] > max) {
			max = arr[i];
			maxIdx = i;
		}
		else if (arr[i] == max) {
			maxIdx = 26;
		}
	}
	if (maxIdx == 26) {
		std::cout << '?';
	}
	else {
		std::cout << (char)(maxIdx + 'A');
	}

	return 0;
}