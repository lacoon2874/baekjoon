#include <iostream>

struct Node {
	int data, bf, count;
	Node* lchild, * rchild;

	Node(int);
};

void insert(Node*&, int, bool&);
void leftRotation(Node*&);
void rightRotation(Node*&);
int search(Node*, int);
void deleteTree(Node*);

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	int n, m;
	
	std::cin >> n;
	Node* root = NULL;
	int temp;
	bool unbalanced;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		insert(root, temp, unbalanced);
	}
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		std::cin >> temp;
		std::cout << search(root, temp) << ' ';
	}

	deleteTree(root);

	return 0;
}

Node::Node(int key) : data(key), bf(0), count(1), lchild(NULL), rchild(NULL) {

}

void insert(Node*& ptr, int key, bool& unbalanced) {
	if (!ptr) {
		ptr = new Node(key);
		unbalanced = true;
	}
	else if (ptr->data == key) {
		ptr->count++;
		unbalanced = false;
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
				leftRotation(ptr);
				unbalanced = false;
				break;
			}
		}
	}
	else {
		insert(ptr->rchild, key, unbalanced);
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
		ptr->rchild = grandChild->lchild;
		child->lchild = grandChild->rchild;
		grandChild->lchild = ptr;
		grandChild->rchild = child;
		switch (grandChild->bf) {
		case -1:
			ptr->bf = 1;
			child->bf = 0;
			break;
		case 0:
			ptr->bf = 0;
			child->bf = 0;
			break;
		case 1:
			ptr->bf = 0;
			child->bf = -1;
			break;
		}
		ptr = grandChild;
	}
	ptr->bf = 0;
}

int search(Node* ptr, int key) {
	if (!ptr) {
		return 0;
	}
	else if (ptr->data == key) {
		return ptr->count;
	}
	else if (key < ptr->data) {
		return search(ptr->lchild, key);
	}
	else {
		return search(ptr->rchild, key);
	}
}

void deleteTree(Node* ptr) {
	if (ptr) {
		deleteTree(ptr->lchild);
		deleteTree(ptr->rchild);
		delete ptr;
	}
}