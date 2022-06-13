#include <iostream>
#include <string>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::string str;
	int count = 0;

	std::cin >> str;
	for (int i = 0; i < str.length(); i++, count++) {
		switch (str[i]) {
		case 'c':
			if (i + 1 < str.length()) {
				if (str[i + 1] == '=') {
					i++;
				}
				else if (str[i + 1] == '-') {
					i++;
				}
			}
			break;
		case 'd':
			if (i + 2 < str.length() && str[i + 1] == 'z' && str[i + 2] == '=') {
				i += 2;
			}
			else if (i + 1 < str.length() && str[i + 1] == '-') {
				i++;
			}
			break;
		case 'l':
			if (i + 1 < str.length() && str[i + 1] == 'j') {
				i++;
			}
			break;
		case 'n':
			if (i + 1 < str.length() && str[i + 1] == 'j') {
				i++;
			}
			break;
		case 's':
			if (i + 1 < str.length() && str[i + 1] == '=') {
				i++;
			}
			break;
		case 'z':
			if (i + 1 < str.length() && str[i + 1] == '=') {
				i++;
			}
			break;
		}
	}
	std::cout << count;

	return 0;
}