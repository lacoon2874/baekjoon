#include <iostream>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int t, a, b;

	std::cin >> t;
	for (int i = 1; i <= t; i++) {
		std::cin >> a >> b;
		std::cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << '\n';
	}
	
	return 0;
}