#include <iostream>

void bubbleSort(int*, int);
void swap(int*, int, int);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;

	std::cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}
	bubbleSort(arr, n);
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << '\n';
	}

	delete[] arr;

	return 0;
}

void bubbleSort(int* arr, int n) {
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr, j, j + 1);
			}
		}
	}
}

void swap(int* arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}