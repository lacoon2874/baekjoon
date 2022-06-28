#include <iostream>
#include <random>

void quickSort(int*, int, int);
void quickSortIndex(int*, int*, int, int);
void swap(int*, int, int);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;

	std::cin >> n;
	int* arrN = new int[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arrN[i];
	}
	std::cin >> m;
	int* arrM = new int[m];
	int* indexM = new int[m];
	for (int i = 0; i < m; i++) {
		std::cin >> arrM[i];
		indexM[i] = i;
	}
	quickSort(arrN, 0, n - 1);
	quickSortIndex(arrM, indexM, 0, m - 1);

	int j = 0;
	for (int i = 0; i < n && j < m;) {
		if (arrN[i] == arrM[indexM[j]]) {
			arrM[indexM[j]] = 1;
			i++;
			j++;
		}
		else if (arrN[i] < arrM[indexM[j]]) {
			i++;
		}
		else {
			arrM[indexM[j++]] = 0;
		}
	}
	for (; j < m; j++) {
		arrM[indexM[j]] = 0;
	}
	for (j = 0; j < m; j++) {
		std::cout << arrM[j] << ' ';
	}
	
	delete[] arrN, arrM, indexM;

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

void quickSortIndex(int* arr, int* index, int l, int r) {
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
		quickSortIndex(arr, index, l, j - 1);
		quickSortIndex(arr, index, j + 1, r);
	}
}

void swap(int* arr, int a, int b) {
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}