#include "Graph.h"

Graph::Graph() {
	std::cout << "Enter number of Nodes:";
	std::cin >> this->size;
	this->nodes = new Node*[this->size];
	for (unsigned int i = 0; i < this->size; i++) {
		this->nodes[i] = new Node(this->size-1);
	}
}

void Graph::addNode(Node* const obj) {
	unsigned int newSize = this->size + 1;
	Node** newNodes = new Node * [newSize];
	for (unsigned int i = 0; i < this->size; i++) {
		newNodes[i] = new Node(*nodes[i],newSize);
	}
	newNodes[size] = new Node(*obj,newSize);
	
	
	for (unsigned int i = 0; i < size; i++) {
		delete nodes[i];
	}
	delete[] nodes;


	this->size = newSize;
	nodes = newNodes;
}

void Graph::removeNode(unsigned int index) {
	unsigned int newSize = this->size - 1;
	Node** newNodes = new Node * [newSize];
	for (unsigned int i = 0; i < index; i++) {
		newNodes[i] = new Node(*nodes[i],newSize);
	}
	for (unsigned int i = index+1; i < size; i++) {
		newNodes[i-1] = new Node(*nodes[i],newSize);
	}

	for (unsigned int i = 0; i < size; i++) {
		delete nodes[i];
	}
	delete[] nodes;


	this->size = newSize;
	nodes = newNodes;
}

void Graph::changeNode() {
	bool input = true;
	do {
		unsigned int index;
		do {
			std::cout << "Which element would you like to change?";
			std::cin >> index;
		} while (index >= size || index < 0);

		unsigned int index2;
		do {
			std::cout << "Which element would you like to connect it to?";
			std::cin >> index2;
		} while (index == index2 || index2 >= size || index2 < 0);

		(*nodes[index]).pushConnection(nodes[index2]);
		std::cout << "Would you like to add a new connection?\n";

	} while (input);
}

void Graph::print()  const {
	for (unsigned int i = 0; i < size; i++) {
		(*nodes[i]).printConnections();
	}
}

unsigned int Graph::getSize() {
	return this->size;
}