#include <iostream>
#include <string>

struct Member {
	int age;
	std::string name;

	bool operator<=(const Member& m) const;
};

Member* temp;

void mergeSort(Member*, int, int);
void merge(Member*, int, int, int);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;

	std::cin >> n;
	Member* arr = new Member[n];
	temp = new Member[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i].age >> arr[i].name;
	}
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		std::cout << arr[i].age << ' ' << arr[i].name << '\n';
	}

	delete[] arr, temp;

	return 0;
}

bool Member::operator<=(const Member& m) const {
	return this->age <= m.age;
}

void mergeSort(Member* arr, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void merge(Member* arr, int l, int m, int r) {
	int i = l, j = m + 1, k = l;

	while (i <= m && j <= r) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		}
		else {
			temp[k++] = arr[j++];
		}
	}
	for (; i <= m; i++, k++) {
		temp[k] = arr[i];
	}
	for (; j <= r; j++, k++) {
		temp[k] = arr[j];
	}
	for (k = l; k <= r; k++) {
		arr[k] = temp[k];
	}
}