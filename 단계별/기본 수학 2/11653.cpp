#include <iostream>
#include <cmath>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	
	std::cin >> n;
	while (!(n % 2)) {
		std::cout << 2 << '\n';
		n /= 2;
	}
	int max = (int)sqrt(n) + 1;
	for (int prime = 3; n > 1 && prime < max;) {
		if (!(n % prime)) {
			std::cout << prime << '\n';
			n /= prime;
		}
		else {
			prime += 2;
		}
	}
	if (n > 1) {
		std::cout << n;
	}

	return 0;
}