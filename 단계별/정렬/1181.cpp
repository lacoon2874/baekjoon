#include <iostream>
#include <vector>
#include <string>
#include <random>

void quickSort(std::vector<std::string>&, int, int);
void swap(std::vector<std::string>&, int, int);
bool lessThan(std::string&, std::string&);
bool moreThan(std::string&, std::string&);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::vector<std::string> input;
	std::string str;
	int n;
	
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> str;
		input.push_back(str);
	}
	quickSort(input, 0, n - 1);
	str = "";
	for (int i = 0; i < n; i++) {
		if (input[i].compare(str)) {
			std::cout << input[i] << '\n';
			str = input[i];
		}
	}

	return 0;
}

void quickSort(std::vector<std::string>& arr, int l, int r) {
	if (l < r) {
		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(l, r);

		int pivot = dis(gen);
		swap(arr, l, pivot);

		int i = l, j = r + 1;
		while (i < j) {
			for (i++; i <= r && lessThan(arr[i], arr[l]); i++);
			for (j--; j > l && moreThan(arr[j], arr[l]); j--);
			if (i < j) {
				swap(arr, i, j);
			}
		}
		swap(arr, l, j);
		quickSort(arr, l, j - 1);
		quickSort(arr, j + 1, r);
	}
}

void swap(std::vector<std::string>& arr, int a, int b) {
	std::string temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

bool lessThan(std::string& a, std::string& b) {
	if (a.length() < b.length()) {
		return true;
	}
	else if (a.length() == b.length() && a.compare(b) < 0) {
		return true;
	}
	else {
		return false;
	}
}

bool moreThan(std::string& a, std::string& b) {
	if (a.length() > b.length()) {
		return true;
	}
	else if (a.length() == b.length() && a.compare(b) > 0) {
		return true;
	}
	else {
		return false;
	}
}