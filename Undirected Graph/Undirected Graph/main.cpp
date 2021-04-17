#include <iostream>
#include <vector>

#include "Node.h"
#include "Graph.h"

void printMenu() {
	std::cout << "What would you like to do?\n";
	std::cout << "1. Add Node.\n";
	std::cout << "2. Remove Node.\n";
	std::cout << "3. Print all connections.\n";
	std::cout << "4. Connect nodes.\n";
	std::cout << "0. Exit\n";
}

int main() {
	Graph a;
	bool bAgain=true;
	int input;
	do {
		do {
			system("CLS");
			printMenu();
			std::cin >> input;
			if (input == 1) {
				Node d(a.getSize());
				std::cout << d.connections() << "\n";
				std::cout<<a.getSize()
				a.addNode(&d);
			}
			else if (input == 2) {
				int index;
				do {
					std::cout << "Enter the index of element to remove: ";
					std::cin >> index;
				} while (index >= a.getSize() || index < 0);
			}
			else if (input == 3) {
				a.print();
			}
			else if (input == 4) {
				a.changeNode();
			}
			else if (input == 0) {
				bAgain = false;
			}
		} while (input != 0 && input != 1 && input != 2 && input != 3 && input != 4);

		if (bAgain) {
			std::cout << "Would you like to go again? (0/1)\n";
			std::cin >> bAgain;
		}
	} while (bAgain);
}