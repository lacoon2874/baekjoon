#include <iostream>

int fact(const int);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	
	std::cin >> n;

	std::cout << fact(n);

	return 0;
}

int fact(const int n) {
	if (n<=1) {
		return 1;
	}
	
	return n * fact(n - 1);
}