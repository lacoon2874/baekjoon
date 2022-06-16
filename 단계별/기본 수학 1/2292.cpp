#include <iostream>
#include <cmath>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	double n;
	int temp;

	std::cin >> n;
	temp = (int)sqrt((n - 1) / 3);
	if (temp * (temp + 1) < (n - 1) / 3) {
		std::cout << temp + 2;
	}
	else {
		std::cout << temp + 1;
	}
	
	return 0;
}