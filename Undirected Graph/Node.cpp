#include "Node.h"

unsigned int Node::id = 1;

Node::Node(unsigned int numberOfConnections) {
	this->numberOfConnections = numberOfConnections;
	this->nodeId = id;
	id++;

	this->connections = new Node*[numberOfConnections]();
}
void Node::print() const {
		std::cout << "Node id = " << this->nodeId << "\n";
}

Node::Node(const Node& obj) {
	this->id = obj.id;
	this->numberOfConnections = obj.numberOfConnections;
	this->connections = new Node * [numberOfConnections]();
	for (int i = 0; i < numberOfConnections; i++) {
		this->connections[i] = obj.connections[i];
	}
}

Node::Node(const Node& obj, unsigned int newSize) {
	this->id = obj.id;
	this->numberOfConnections = newSize-1;
	this->connections = new Node * [numberOfConnections]();
	for (int i = 0; i < this->numberOfConnections; i++) {
		this->connections[i] = obj.connections[i];
	}
}
void Node::pushConnection(Node* const  obj){
	int index = 0;
	bool enter = false;
	for (unsigned int i = 0; i < numberOfConnections; i++) {
		if (connections[i] != nullptr) {
			if (connections[i]->getId() == obj->getId()) {
				std::cout << "You cannot add the same connection as a connection!\n";
				return;
			}
		}
		else {
			if (!enter) {
				index = i;
				enter = true;
			}
		}
	}
	connections[index]=obj;
}

void Node::printConnections() const {
	std::cout << "Node: " << this->getId() << " connected with:\n";
	for (unsigned cnt = 0; cnt < numberOfConnections; cnt++) {
		if (connections[cnt] != nullptr) {
			std::cout << "\tNode: " << (*connections[cnt]).getId();
		}
	}
	std::cout << "\n";
}

unsigned int Node::getNumberOfConnections() const{
	return this->numberOfConnections;
}

unsigned int Node::getId() const {
	return this->nodeId;
}


void Node::setId(unsigned int newId) {
	this->nodeId = newId;
}



unsigned int Node::getNodeId() {
	return id;
}