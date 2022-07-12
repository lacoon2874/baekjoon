#include <iostream>

bool maxFront(int, int);
void swap(int&, int&);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int a, b, c;
	std::cin >> a >> b >> c;
	while (a != 0 && b != 0 && c != 0) {
		if (!maxFront(a, b)) {
			swap(a, b);
		}
		if (maxFront(a, c)) {
			swap(a, c);
		}
		if (a * a + b * b == c * c) {
			std::cout << "right\n";
		}
		else {
			std::cout << "wrong\n";
		}

		std::cin >> a >> b >> c;
	}

	return 0;
}

bool maxFront(int a, int b) {
	if (a > b) {
		return true;
	}
	else {
		return false;
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}