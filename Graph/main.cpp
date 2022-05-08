#include <iostream>
#include "Graph.h"

void dg_test() {
	Graph<int> graph(std::vector<std::pair<std::vector<int>, bool>> {
        { {1,6}, true },
        { {2,3}, true },
        { {3,4}, true },
        { {6,5}, true },
        { {5,4}, true },
        { {1,2}, true },
        { {2,4}, true },
    });

	graph.print_graph();
    std::cout << "\n";
	graph.print_sorted_graph();
    graph.print_shortest_path(1,4);
}

int main() {
	dg_test();
}