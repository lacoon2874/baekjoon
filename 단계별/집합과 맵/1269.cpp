#include <iostream>
#include <random>

void quickSort(int*, int, int);
void swap(int*, int, int);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int a, b;

	std::cin >> a >> b;
	int* arrA = new int[a];
	for (int i = 0; i < a; i++) {
		std::cin >> arrA[i];
	}
	int* arrB = new int[b];
	for (int i = 0; i < b; i++) {
		std::cin >> arrB[i];
	}
	quickSort(arrA, 0, a - 1);
	quickSort(arrB, 0, b - 1);

	int i = 0, j = 0, count = 0;
	while (i < a && j < b) {
		if (arrA[i] == arrB[j]) {
			i++;
			j++;
		}
		else {
			count++;
			if (arrA[i] < arrB[j]) {
				i++;
			}
			else {
				j++;
			}
		}
	}
	for (; i < a; i++) {
		count++;
	}
	for (; j < b; j++) {
		count++;
	}
	std::cout << count;

	delete[] arrA, arrB;

	return 0;
}

void quickSort(int* arr, int l, int r) {
	if (l < r) {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(l, r);

		int pivot = dis(gen);
		swap(arr, l, pivot);

		int i = l, j = r + 1;
		while (i < j) {
			for (i++; i <= r && arr[i] < arr[l]; i++);
			for (j--; j > l && arr[j] > arr[l]; j--);
			if (i < j) {
				swap(arr, i, j);
			}
		}
		swap(arr, l, j);
		quickSort(arr, l, j - 1);
		quickSort(arr, j + 1, r);
	}
}

void swap(int* arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}