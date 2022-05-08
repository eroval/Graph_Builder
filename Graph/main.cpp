#include <iostream>
#include "Graph.h"

void dg_test() {
	Graph<int> graph(std::vector<std::pair<std::vector<int>, bool>> {
        { {1, 2}, true },
        { {9,5}, false},
        { {9,8}, true },
        { {9,10}, true },
        { {14,5}, false },
        { {14,6}, false },
        { {7,8}, true },
        { {14,6}, false },
        { {2,3}, true },
        { {3,4}, true },
        { {4,5}, true },
        { {10,14}, false },
        { {5,6}, true },
        { {3,4}, true },
        { {1,2}, true },
        { {2,3}, true },
        { {1,7}, true },
    });

	graph.print_graph();
    std::cout << "\n";
	graph.print_sorted_graph();
    std::cout << "\n";
    graph.print_shortest_path(1,14);
}

int main() {
	dg_test();
}