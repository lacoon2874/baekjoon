#include <iostream>
#include <string>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::string a, b;

	std::cin >> a >> b;
	std::string temp;
	if (b.length() > a.length()) {
		temp = a;
		a = b;
		b = temp;
	}
	int i = a.length() - 1;
	int sum = 0;
	for (int j = b.length() - 1; j >= 0; i--, j--) {
		sum = sum + a[i] - '0' + b[j] - '0';
		a[i] = sum % 10 + '0';
		sum /= 10;
	}
	for (; sum && i >= 0; i--) {
		sum = sum + a[i] - '0';
		a[i] = sum % 10 + '0';
		sum /= 10;
	}
	if (sum) {
		std::cout << sum;
	}
	std::cout << a;

	return 0;
}