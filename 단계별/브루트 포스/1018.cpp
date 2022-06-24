#include <iostream>
#include <string>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;
	
	std::cin >> n >> m;
	std::string* input = new std::string[n];
	for (int i = 0; i < n; i++) {
		std::cin >> input[i];
	}
	int min = n * m, countB, countW, colorIndex = 0;
	char color[2] = { 'B', 'W' };
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			countB = 0;
			countW = 0;
			for (int k = i; k < i + 8; k++) {
				for (int m = j; m < j + 8; m++) {
					if (input[k][m] != color[colorIndex]) {
						countB++;
					}
					else {
						countW++;
					}
					colorIndex = (colorIndex + 1) % 2;
				}
				colorIndex = (colorIndex + 1) % 2;
			}
			if (countB < min) {
				min = countB;
			}
			if (countW < min) {
				min = countW;
			}
		}
	}
	std::cout << min;

	delete[] input;

	return 0;
}