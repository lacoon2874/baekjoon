#include <iostream>

int fibo(int);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;

	std::cin >> n;
	std::cout << fibo(n);

	return 0;
}

int fibo(int n) {
	if (n <= 1) {
		return n;
	}

	return fibo(n - 1) + fibo(n - 2);
}