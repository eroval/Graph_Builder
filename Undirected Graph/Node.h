#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>

class Node {
private:
	Node** connections;
	unsigned int nodeId;
	unsigned int numberOfConnections;
public:
	static unsigned int id;
	Node(unsigned int = 0);
	Node(const Node&);
	Node(const Node&, unsigned int);


	void print() const;
	void printConnections() const;

	void pushConnection(Node* const);

	unsigned int getNumberOfConnections() const;
	unsigned int getId() const;

	void setId(unsigned int);


	static unsigned int getNodeId();
};

#endif // NODE
