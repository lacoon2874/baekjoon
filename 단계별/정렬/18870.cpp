#include <iostream>
#include <random>

void quickSort(int*, int*, int, int);
void swap(int*, int, int);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;

	std::cin >> n;
	int* arr = new int[n];
	int* index = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
		index[i] = i;
	}
	quickSort(arr, index, 0, n - 1);
	int before = arr[index[0]];
	int count = 0;
	arr[index[0]] = count;
	for (int i = 1; i < n; i++) {
		if (arr[index[i]] != before) {
			before = arr[index[i]];
			arr[index[i]] = ++count;
		}
		else {
			arr[index[i]] = count;
		}
	}
	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << ' ';
	}

	delete[] arr, index;

	return 0;
}

void quickSort(int* arr, int* index, int l, int r) {
	if (l < r) {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(l, r);

		int pivot = dis(gen);
		swap(index, l, pivot);

		int i = l, j = r + 1;
		while (i < j) {
			for (i++; i <= r && arr[index[i]] < arr[index[l]]; i++);
			for (j--; j > l && arr[index[j]] > arr[index[l]]; j--);
			if (i < j) {
				swap(index, i, j);
			}
		}
		swap(index, l, j);
		quickSort(arr, index, l, j - 1);
		quickSort(arr, index, j + 1, r);
	}
}

void swap(int* index, int a, int b) {
	int temp = index[a];
	index[a] = index[b];
	index[b] = temp;
}