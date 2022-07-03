#include <iostream>
#include <random>

void quickSort(std::string*, int, int);
void swap(std::string*, int, int);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;

	std::cin >> n >> m;
	std::string* arrN = new std::string[n];
	std::string* arrM = new std::string[m];
	for (int i = 0; i < n; i++) {
		std::cin >> arrN[i];
	}
	for (int i = 0; i < m; i++) {
		std::cin >> arrM[i];
	}
	quickSort(arrN, 0, n - 1);
	quickSort(arrM, 0, m - 1);

	bool* index = new bool[n];
	for (int i = 0; i < n; i++) {
		index[i] = false;
	}
	int count = 0;
	for (int i = 0, j = 0; i < n && j < m;) {
		if (arrN[i].compare(arrM[j]) == 0) {
			index[i] = true;
			count++;
			i++;
			j++;
		}
		else if (arrN[i].compare(arrM[j]) < 0) {
			i++;
		}
		else {
			j++;
		}
	}
	std::cout << count << '\n';
	for (int i = 0; i < n; i++) {
		if (index[i]) {
			std::cout << arrN[i] << '\n';
		}
	}

	delete[] arrN, arrM, index;

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