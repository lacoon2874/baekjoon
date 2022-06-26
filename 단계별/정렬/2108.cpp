#include <iostream>
#include <cmath>

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	int arr[8001];

	for (int i = 0; i < 8001; i++) {
		arr[i] = 0;
	}
	std::cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		arr[temp + 4000]++;
	}
	double mean = 0;
	int medianCount = 0, median = -4001;
	int modeCount = -1, mode;
	bool isSecond;
	int min = 8001, max = -1;
	for (int i = 0; i < 8001; i++) {
		mean += (double)arr[i] * (i - 4000);
		medianCount += arr[i];
		if (medianCount > n / 2 && median < -4000) {
			median = i - 4000;
		}
		if (arr[i] > modeCount) {
			modeCount = arr[i];
			mode = i - 4000;
			isSecond = false;
		}
		else if (arr[i] == modeCount && !isSecond) {
			mode = i - 4000;
			isSecond = true;
		}
		if (arr[i]) {
			if (i < min) {
				min = i;
			}
			if (i > max) {
				max = i;
			}
		}
	}
	min -= 4000;
	max -= 4000;
	
	std::cout << floor((mean / n) + 0.5) << '\n';
	std::cout << median << '\n';
	std::cout << mode << '\n';
	std::cout << max - min << '\n';

	return 0;
}