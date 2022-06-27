#include <iostream>
#include <random>

struct Pos {
	int x, y;

	bool operator<(const Pos&) const;
	bool operator>(const Pos&) const;
};

void quickSort(Pos*, int, int);
void swap(Pos*, int, int);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	
	std::cin >> n;
	Pos* arr = new Pos[n];
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i].x >> arr[i].y;
	}
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		std::cout << arr[i].x << ' ' << arr[i].y << '\n';
	}

	delete[] arr;

	return 0;
}

bool Pos::operator<(const Pos& p) const {
	if (this->y < p.y) {
		return true;
	}
	else if (this->y == p.y && this->x < p.x) {
		return true;
	}
	else {
		return false;
	}
}

bool Pos::operator>(const Pos& p) const {
	if (this->y > p.y) {
		return true;
	}
	else if (this->y == p.y && this->x > p.x) {
		return true;
	}
	else {
		return false;
	}
}

void quickSort(Pos* arr, int l, int r) {
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

void swap(Pos* arr, int a, int b) {
	Pos temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}