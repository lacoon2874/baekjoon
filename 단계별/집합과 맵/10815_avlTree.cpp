#include <iostream>

struct Node {
	int data, bf;
	Node* lchild, * rchild;

	Node(int);
};

void insert(Node*&, int, bool&);
void leftRotation(Node*&, bool&);
void rightRotation(Node*&, bool&);
bool search(Node*, int);
void deleteTree(Node*);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n;
	Node* root = NULL;
	
	std::cin >> n;
	int temp;
	bool unbalanced;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		insert(root, temp, unbalanced);
	}
	int m;
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> temp;
		if (search(root, temp)) {
			std::cout << "1 ";
		}
		else {
			std::cout << "0 ";
		}
	}

	deleteTree(root);

	return 0;
}

Node::Node(int key) : data(key), bf(0), lchild(NULL), rchild(NULL) {

}

void insert(Node*& ptr, int key, bool& unbalanced) {
	if (!ptr) {
		unbalanced = true;
		ptr = new Node(key);
	}
	else if (key < ptr->data) {
		insert(ptr->lchild, key, unbalanced);
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
				leftRotation(ptr, unbalanced);
				break;
			}
		}
	}
	else {
		insert(ptr->rchild, key, unbalanced);
		if (unbalanced) {
			switch (ptr->bf) {
			case -1:
				rightRotation(ptr, unbalanced);
				break;
			case 0:
				ptr->bf = -1;
				break;
			case 1:
				unbalanced = false;
				ptr->bf = 0;
				break;
			}
		}
	}
}

void leftRotation(Node*& ptr, bool& unbalanced) {
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
	unbalanced = false;
}

void rightRotation(Node*& ptr, bool& unbalanced) {
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
			break;
		}
		ptr = grandChild;
	}
	ptr->bf = 0;
	unbalanced = false;
}

bool search(Node* ptr, int key) {
	while (ptr) {
		if (key == ptr->data) {
			return true;
		}
		else if (key < ptr->data) {
			ptr = ptr->lchild;
		}
		else {
			ptr = ptr->rchild;
		}
	}
	return false;
}

void deleteTree(Node* ptr) {
	if (ptr) {
		deleteTree(ptr->lchild);
		deleteTree(ptr->rchild);
		delete ptr;
	}
}