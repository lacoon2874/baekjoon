#include <iostream>

struct Person {
	int weight;
	int height;
	int rank;
};

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;

	std::cin >> n;
	Person* person = new Person[n];
	for (int i = 0; i < n; i++) {
		std::cin >> person[i].weight >> person[i].height;
		person[i].rank = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (person[i].weight < person[j].weight && person[i].height < person[j].height) {
				person[i].rank++;
			}
		}
		std::cout << person[i].rank << ' ';
	}

	delete[] person;

	return 0;
}