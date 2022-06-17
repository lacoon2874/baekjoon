#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, answer = 0;

	std::cin >> n;
	switch (n % 5) {
	case 1:
		n -= 6;
		answer += 2;
		break;
	case 2:
		n -= 10;
		answer += 4;
		break;
	case 3:
		n -= 3;
		answer += 1;
		break;
	case 4:
		n -= 9;
		answer += 3;
		break;
	}
	if (n < 0) {
		std::cout << -1;
	}
	else {
		std::cout << (n / 5) + answer;
	}

	return 0;
}