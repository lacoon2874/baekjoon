#include <iostream>

void printStar(const int, const int, const char, const char);
void printRow(const int, const char, const bool);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	char cur = 1;
	
	std::cin >> n;
	printStar(n, n, cur, 0);

	return 0;
}

void printStar(const int row, const int size, const char cur, const char count) {
	if (row == 1) {
		printRow(size, count, false);
		std::cout << '\n';

		return;
	}
	char next = cur << 1;
	printStar(row / 3, size, next, count);
	printStar(row / 3, size, next, (count | cur));
	printStar(row / 3, size, next, count);
}

void printRow(const int size, const char count, const bool isEmpty) {
	if (isEmpty) {
		for (int i = 0; i < size; i++) {
			std::cout << ' ';
		}

		return;
	}
	if (size == 1) {
		std::cout << '*';
		
		return;
	}
	if (count & 1) {
		printRow(size / 3, count >> 1, isEmpty);
		printRow(size / 3, count >> 1, true);
		printRow(size / 3, count >> 1, isEmpty);
	}
	else {
		for (int i = 0; i < 3; i++) {
			printRow(size / 3, count >> 1, isEmpty);
		}
	}
}