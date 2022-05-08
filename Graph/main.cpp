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
        { {8,10}, false },
    });

    Graph<int> graph2(std::vector<std::pair<std::vector<int>, bool>> {
        { {1, 3, 1}, false },
        { {1,2,1},true },
        { {9,2,10},false },
        { {3,4,15},false },
        { {5,4,2},false },
        { {4,1,1},false},
        { {4,9,4},false },
        { {6,7,3},false },
        { {6,5,1},false },
        { {7,5,9},false },
        { {9,7,18},false }
    });

	graph.print_graph();
    std::cout << "\n";
	graph.print_sorted_graph();
    std::cout << "\n";
    graph.print_shortest_path(1,3);
    graph2.print_shortest_path(1, 7);
}

int main() {
	dg_test();
}