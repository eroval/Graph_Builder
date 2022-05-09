#include <iostream>
#include "Graph.h"

void dg_test() {
    // test 1
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

    // test 2
    Graph<int> graph2(std::vector<std::pair<std::vector<int>, bool>> {
        { {1, 3, 1}, true },
        { {1,2,1},true },
        { {2,9,10},true },
        { {3,4,15},true },
        { {1,4,1},true },
        { {4,9,4},true },
        { {4,9,2},true },
        { {5,6,1},true },
        { {6,7,3},true },
        { {7,9,18},true }
    });

    // test 3
    Graph<int> graph3(std::vector<std::pair<std::vector<int>, bool>> {
        { {1, 3, 1}, false },
        { {1,2,1},true },
        { {9,2,10},false },
        { {3,4,15},false },
        { {5,4,2},false },
        { {4,1,1},false },
        { {4,9,4},false },
        { {6,7,3},false },
        { {6,5,1},false },
        { {7,5,9},false },
        { {9,7,18},false }
    });

    Graph<int> graph4(std::vector<std::pair<std::vector<int>, bool>> {
        { {1, 2, 10}, true },
        { {2,8,5} ,true },
        { {1,5,1},true },
        { {5,8,2},true },
        { {5,7,1},true },
        { {7,8,3},true },
        { {8,10,1},true },
        { {10,11,20},true },
        { {11,3,20},true },
        { {3,4,2},true },
        { {3,2,5},false },
        { {4,2,1},false }
    });

    graph.print_shortest_path(1,3);
    std::cout << "\n";
    graph2.print_shortest_path(1,7);
    std::cout << "\n";
    graph3.print_shortest_path(1, 7);
    std::cout << "\n";
    graph4.print_shortest_path(1,3);
}

int main() {
	dg_test();
}