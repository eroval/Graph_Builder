#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"

class Graph {
private:
	Node** nodes;
	unsigned int size;
public:
	Graph();
	Graph(const Graph&) = delete;
	void addNode(Node* const); 
	void removeNode(unsigned int);
	void changeNode();
	void print() const;

	unsigned int getSize();
};


#endif //GRAPH_H