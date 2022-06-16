#include <iostream>
#include <cmath>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	double n;
	int temp, seq;

	std::cin >> n;
	temp = (int)sqrt(2 * n);
	if (temp * (temp + 1) < 2 * n) {
		temp++;
	}
	seq = temp * (temp + 1) / 2 - (int)n;
	if (temp % 2) {
		std::cout << 1 + seq << '/' << temp - seq;
	}
	else {
		std::cout << temp - seq << '/' << 1 + seq;
	}

	return 0;
}