#include <iostream>
#include <string>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::string a, b;
	
	std::cin >> a >> b;
	bool isA;

	if (a[2] < b[2]) {
		isA = false;
	}
	else if (a[2] > b[2]) {
		isA = true;
	}
	else {
		if (a[1] < b[1]) {
			isA = false;
		}
		else if (a[1] > b[1]) {
			isA = true;
		}
		else {
			if (a[0] < b[0]) {
				isA = false;
			}
			else {
				isA = true;
			}
		}
	}
	if (isA) {
		for (int i = 2; i >= 0; i--) {
			std::cout << a[i];
		}
	}
	else {
		for (int i = 2; i >= 0; i--) {
			std::cout << b[i];
		}
	}

	return 0;
}