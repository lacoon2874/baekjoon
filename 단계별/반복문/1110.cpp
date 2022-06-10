#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, temp, sum, count = 0;

	std::cin >> n;
	temp = n;
	do {
		sum = temp / 10 + temp % 10;
		temp = (temp % 10) * 10 + sum % 10;
		count++;
	} while (temp != n);
	std::cout << count;

	return 0;
}