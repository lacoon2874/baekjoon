#include <iostream>
#include <string>
#include <random>

void quickSort(std::string*, int, int);
void swap(std::string*, int, int);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;

	std::cin >> n >> m;
	std::string* arr1 = new std::string[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr1[i];
	}
	std::string* arr2 = new std::string[m];
	for (int i = 0; i < m; i++) {
		std::cin >> arr2[i];
	}
	quickSort(arr1, 0, n - 1);
	quickSort(arr2, 0, m - 1);

	int count = 0, retVal;
	for (int i = 0, j = 0; i < n && j < m;) {
		retVal = arr1[i].compare(arr2[j]);
		if (retVal == 0) {
			count++;
			j++;
		}
		else if (retVal < 0) {
			i++;
		}
		else {
			j++;
		}
	}
	std::cout << count;

	delete[] arr1, arr2;

	return 0;
}

void quickSort(std::string* arr, int l, int r) {
	if (l < r) {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(l, r);

		int pivot = dis(gen);
		swap(arr, l, pivot);

		int i = l, j = r + 1;
		while (i < j) {
			for (i++; i <= r && arr[i].compare(arr[l]) < 0; i++);
			for (j--; j > l && arr[j].compare(arr[l]) > 0; j--);
			if (i < j) {
				swap(arr, i, j);
			}
		}
		swap(arr, l, j);
		quickSort(arr, l, j - 1);
		quickSort(arr, j + 1, r);
	}
}

void swap(std::string* arr, int a, int b) {
	std::string temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}