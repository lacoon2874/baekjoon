#include <iostream>
#include <string>
#include <random>

struct Node {
	int data, bf;
	Node* lchild, * rchild;

	Node(int);
};

void insert(std::string*, Node*&, int, bool&);
void leftRotation(Node*&);
void rightRotation(Node*&);
int search(std::string*, Node*, std::string&);
void deleteTree(Node*);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;

	std::cin >> n >> m;
	std::string* arr = new std::string[n + 1];
	Node* root = NULL;
	bool unbalanced;
	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i];
		insert(arr, root, i, unbalanced);
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

Node::Node(int k) : data(k), bf(0), lchild(NULL), rchild(NULL) {

}

void insert(std::string* arr, Node*& ptr, int key, bool& unbalanced) {
	if (!ptr) {
		unbalanced = true;
		ptr = new Node(key);
	}
	else if (arr[key].compare(arr[ptr->data]) < 0) {
		insert(arr, ptr->lchild, key, unbalanced);
		if (unbalanced) {
			switch (ptr->bf) {
			case -1:
				ptr->bf = 0;
				unbalanced = false;
				break;
			case 0:
				ptr->bf = 1;
				break;
			case 1:
				leftRotation(ptr);
				unbalanced = false;
				break;
			}
		}
	}
	else {
		insert(arr, ptr->rchild, key, unbalanced);
		if (unbalanced) {
			switch (ptr->bf) {
			case -1:
				rightRotation(ptr);
				unbalanced = false;
				break;
			case 0:
				ptr->bf = -1;
				break;
			case 1:
				ptr->bf = 0;
				unbalanced = false;
				break;
			}
		}
	}
}

void leftRotation(Node*& ptr) {
	Node* child = ptr->lchild;

	if (child->bf == 1) {
		ptr->lchild = child->rchild;
		child->rchild = ptr;
		ptr->bf = 0;
		ptr = child;
	}
	else {
		Node* grandChild = child->rchild;
		child->rchild = grandChild->lchild;
		ptr->lchild = grandChild->rchild;
		grandChild->lchild = child;
		grandChild->rchild = ptr;
		switch (grandChild->bf) {
		case -1:
			child->bf = 1;
			ptr->bf = 0;
			break;
		case 0:
			child->bf = 0;
			ptr->bf = 0;
			break;
		case 1:
			child->bf = 0;
			ptr->bf = -1;
			break;
		}
		ptr = grandChild;
	}
	ptr->bf = 0;
}

void rightRotation(Node*& ptr) {
	Node* child = ptr->rchild;

	if (child->bf == -1) {
		ptr->rchild = child->lchild;
		child->lchild = ptr;
		ptr->bf = 0;
		ptr = child;
	}
	else {
		Node* grandChild = child->lchild;
		child->lchild = grandChild->rchild;
		ptr->rchild = grandChild->lchild;
		grandChild->rchild = child;
		grandChild->lchild = ptr;
		switch (grandChild->bf) {
		case -1:
			child->bf = 0;
			ptr->bf = 1;
			break;
		case 0:
			child->bf = 0;
			ptr->bf = 0;
			break;
		case 1:
			child->bf = -1;
			ptr->bf = 0;
		}
		ptr = grandChild;
	}
	ptr->bf = 0;
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