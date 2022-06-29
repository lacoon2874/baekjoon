#include <iostream>
#include <string>
#include <random>

struct Node {
	int data;
	Node* lchild, * rchild;

	Node(int);
};

void insert(std::string*, Node*&, int);
int search(std::string*, Node*, std::string&);
void deleteTree(Node*);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;

	std::cin >> n >> m;
	std::string* arr = new std::string[n + 1];
	Node* root = NULL;
	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i];
		insert(arr, root, i);
	}
	std::string temp;
	int num;
	for (int i = 0; i < m; i++) {
		std::cin >> temp;
		if (temp[0] >= '0' && temp[0] <= '9') {
			num = std::stoi(temp);
			std::cout << arr[num] << '\n';
		}
		else {
			std::cout << search(arr, root, temp) << '\n';
		}
	}

	delete[] arr;
	deleteTree(root);

	return 0;
}

Node::Node(int k) : data(k), lchild(NULL), rchild(NULL) {

}

void insert(std::string* arr, Node*& ptr, int key) {
	if (!ptr) {
		ptr = new Node(key);
	}
	else if (arr[key].compare(arr[ptr->data]) < 0) {
		insert(arr, ptr->lchild, key);
	}
	else {
		insert(arr, ptr->rchild, key);
	}
}

int search(std::string* arr, Node* ptr, std::string& key) {
	if (key.compare(arr[ptr->data]) == 0) {
		return ptr->data;
	}
	else if (key.compare(arr[ptr->data]) < 0) {
		return search(arr, ptr->lchild, key);
	}
	else {
		return search(arr, ptr->rchild, key);
	}
}

void deleteTree(Node* ptr) {
	if (ptr) {
		deleteTree(ptr->lchild);
		deleteTree(ptr->rchild);
		delete ptr;
	}
}