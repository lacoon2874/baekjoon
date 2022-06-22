#include <iostream>

void answer(const int);
void recFunc(const int, const int);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;

	std::cin >> n;
	answer(n);

	return 0;
}

void answer(const int n) {
	std::cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	recFunc(n, 0);
}

void recFunc(const int n, const int cur) {
	if (cur == n) {
		for (int i = 0; i < cur; i++) {
			std::cout << "____";
		}
		std::cout << "\"����Լ��� ������?\"\n";
		for (int i = 0; i < cur; i++) {
			std::cout << "____";
		}
		std::cout << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}
	else {
		for (int i = 0; i < cur; i++) {
			std::cout << "____";
		}
		std::cout << "\"����Լ��� ������?\"\n";
		for (int i = 0; i < cur; i++) {
			std::cout << "____";
		}
		std::cout << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		for (int i = 0; i < cur; i++) {
			std::cout << "____";
		}
		std::cout << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		for (int i = 0; i < cur; i++) {
			std::cout << "____";
		}
		std::cout << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		recFunc(n, cur + 1);
	}
	for (int i = 0; i < cur; i++) {
		std::cout << "____";
	}
	std::cout << "��� �亯�Ͽ���.\n";
}