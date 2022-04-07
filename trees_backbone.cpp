#include <iostream>
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>

class Node {

private:
	int h=1;
	int val;
	Node* left;
	Node* right;

public:

	Node(int val) {
		this->val = val;
		left = nullptr;
		right = nullptr;
	}

	Node(int val, int h) {
		this->val = val;
		this->h = h;
		left = nullptr;
		right = nullptr;
	}


	void setValue(int val) {
		this->val = val;
	}

	int getValue() {
		return this->val;
	}

	int getHeight() {
		return this->h;
	}

	int compareTo(Node* node) {
		if (this->val == node->val) return 0;
		if (this->val < node->val) return -1;
		return 1;
	}

	int compareTo(int val) {
		if (this->val == val) return 0;
		if (this->val < val) return -1;
		return 1;
	}

	void insert(int val) {
		if (compareTo(val) == -1) {
			this->right = new Node(val, this->h+1);
		}
		else this->left = new Node(val, this->h+1);
	}

	Node* getRight() {
		return this->right;
	}

	Node* getLeft() {
		return this->left;
	}
};



class BST {

private:
	Node* root;
	int maxDepth = 1;

public:

	BST() {
		this->root = new Node(0);
	}

	BST(int val){
		this->root = new Node(val);
	}



	void insert(int val) {
		Node* nextptr = root;
		Node* ptr = nextptr;
		while (nextptr != nullptr) {
			ptr = nextptr;
			switch (nextptr->compareTo(val)) {
			case 0: 
				return;
				break;
			case 1:
				nextptr = nextptr->getLeft();
				break;
			case -1:
				nextptr = nextptr->getRight();
				break;

			}
		}
		ptr->insert(val);
		if (ptr->getHeight() == maxDepth ) {
			++maxDepth;
		}
	}

	void print() {
		std::queue<Node> q;
		q.push(*root);
		int h = q.front().getHeight();
		int indent = 10;
		while (!q.empty()) {
			auto node = q.front();
			if (indent) {
				std::cout << std::setw(indent) << ' ';
			}

			if (node.getHeight() > h) {
				std::cout << "\n";
				h = node.getHeight();
				indent+=4; 
			}

			/*
			if(p->right) {
            postorder(p->right, indent+4);
			}
			if (indent) {
				std::cout << std::setw(indent) << ' ';
			}
			if (p->right) std::cout<<" /\n" << std::setw(indent) << ' ';
			std::cout<< p->key_value << "\n ";
			if(p->left) {
				std::cout << std::setw(indent) << ' ' <<" \\\n";
				postorder(p->left, indent+4);
			}

			*/

			std::cout << std::setw(indent) << "[" << node.getValue() << "|" << node.getHeight() << "]";
			if (node.getLeft() != nullptr) {
				q.push(*node.getLeft());
			}
			if (node.getRight() != nullptr) {
				q.push(*node.getRight());
			}

			q.pop();
		}
	}

};


/*
	 6
 3	     9
1    5   7   10
		  8

            6
        1        3 
      1   5    7   10
                8
  */
int main() {
	BST a(6);
	a.insert(3);
	a.insert(9);
	a.insert(1);
	a.insert(5);
	a.insert(7);
	a.insert(10);
	a.insert(8);
	a.print();
	return 0;
}