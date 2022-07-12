#include <iostream>
#include <string>

struct Node {
	std::string data;
	Node* lchild, * rchild;

	Node(std::string&);
};

class Hash {
	int size;
	Node** root;

	void deleteNode(Node*);

public:
	Hash(int);
	~Hash();

	bool insertKey(std::string&);
};

int main(void) {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);

	std::string input, temp;
	std::cin >> input;
	int count = 0;
	for (int i = 0; i < input.length(); i++) {
		Hash hash(26);
		for (int j = 0; j < input.length() - i; j++) {
			temp = input.substr(j, i + 1);
			if (hash.insertKey(temp)) {
				count++;
			}
		}
	}
	std::cout << count;

	return 0;
}

Node::Node(std::string& str) :data(str), lchild(NULL), rchild(NULL) {

}

void Hash::deleteNode(Node* ptr) {
	if (ptr) {
		deleteNode(ptr->lchild);
		deleteNode(ptr->rchild);
		delete ptr;
	}
}

Hash::Hash(int n) : size(n) {
	root = new Node * [size];
	
	for (int i = 0; i < size; i++) {
		root[i] = NULL;
	}
}

Hash::~Hash() {
	for (int i = 0; i < size; i++) {
		deleteNode(root[i]);
	}

	delete[] root;
}

bool Hash::insertKey(std::string& str) {
	int bucket = str[0] - 'a';

	Node* before = NULL;
	bool isLeft;
	for (Node* search = root[bucket]; search;) {
		if (str.compare(search->data) == 0) {
			return false;
		}
		else {
			before = search;
			if (str.compare(search->data) < 0) {
				search = search->lchild;
				isLeft = true;
			}
			else {
				search = search->rchild;
				isLeft = false;
			}
		}
	}
	Node* temp = new Node(str);
	if (!before) {
		root[bucket] = temp;
	}
	else {
		if (isLeft) {
			before->lchild = temp;
		}
		else {
			before->rchild = temp;
		}
	}

	return true;
}