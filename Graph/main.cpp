#include <iostream>
#include "Graph.h"

void dg_test() {
	Graph<int> graph(std::vector<std::pair<std::vector<int>, bool>> {
        { {2, 1}, true },
        { {0, 1}, true},
        { {4,2},false },
        { {0,2},false },
        { {3,4},false }
    });

	graph.print_graph();
    std::cout << "\n";
	graph.print_sorted_graph();

}

int main() {
	dg_test();
}