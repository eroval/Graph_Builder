#include <iostream>
#include "Graph.h"

void dg_test() {
	Graph<int> graph(std::vector<std::pair<std::vector<int>, bool>> {
        { {10, 11}, true },
        { {1, 2}, true },
        { {2,4}, true },
        { {7,5}, false },
        { {5,1}, true },
        { {3,1}, false },
        { {11,3}, false },
        { {5,8}, false },
        { {3,2}, false },
        { {3,4}, false },
        { {10,8}, false },
    });

	graph.print_graph();
    std::cout << "\n";
	graph.print_sorted_graph();
    std::cout << "\n";
    graph.print_shortest_path(1,3);
}

int main() {
	dg_test();
}