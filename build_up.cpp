// This is going to be the backbone of the whole library
// A roadmap for the testing purposes

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <stack>
#include <queue>






namespace ArrayFunctions {
	template <typename T>
	void print_array(std::vector<T>& arr) {
		if (!arr.empty()) {
			std::cout << "{ ";
			std::cout << arr[0];
			for (unsigned long long i = 1; i < arr.size(); ++i) {
				std::cout << ", " << arr[i];
			}
			std::cout << " }";
		}
	}

	template <typename T>
	void print_2D_array(std::vector<std::vector<T>>& arr) {
		for (unsigned long long i = 0; i < arr.size(); ++i) {
			print_array(arr[i]);
		}
	}

	template <typename T, typename V>
	void print_pair(std::pair<T, V>& pair) {
		std::cout << "[" << pair.first << ":" << pair.second << "]";
	}

	template <typename T, typename V>
	void print_pair_array(std::vector<std::pair<T, V>>& arrPair) {
		if (!arrPair.empty()) {
			std::cout << "{ ";
			print_pair(arrPair[0]);
			for (unsigned long long i = 1; i < arrPair.size(); ++i) {
				std::cout << ", ";
				print_pair(arrPair[i]);
			}
			std::cout << " }";
		}
	}

	template <typename T, typename V>
	void print_pair_array_first_elements(std::vector<std::pair<T, V>>& arrPair) {
		if (!arrPair.empty()) {
			std::cout << "{ ";
			std::cout << arrPair[0].first;
			for (unsigned long long i = 1; i < arrPair.size(); ++i) {
				std::cout << ", " << arrPair[i].first;
			}
			std::cout << " }";
		}
	}

	template <typename T, typename V>
	void print_pair_array_second_elements(std::vector<std::pair<T, V>>& arrPair) {
		if (!arrPair.empty()) {
			std::cout << "{ ";
			std::cout << arrPair[0].second;
			for (unsigned long long i = 1; i < arrPair.size(); ++i) {
				std::cout << ", " << arrPair[i].second;
			}
			std::cout << " }";
		}
	}
}












template <typename T>
class UndirectedGraph {
private:
	std::map<T,std::vector<T>> edges;
	
public:
	// CONSTRUCTORS
	UndirectedGraph () = delete;

	UndirectedGraph(std::vector<std::vector<T>> listOfEdges) {
		for (unsigned long long i = 0; i < listOfEdges.size(); ++i) {
			edges[listOfEdges[i][0]].push_back(listOfEdges[i][1]);
			edges[listOfEdges[i][1]].push_back(listOfEdges[i][0]);
		}

		for (auto& x : edges) {
			std::sort(x.second.begin(), x.second.end());
		}
	}

	// PRINTS
	void print_graph () {
		for (auto x : edges) {
			std::cout << x.first << ": ";
			ArrayFunctions::print_array(x.second);
			std::cout << "\n";
		}
	}
};

template <typename T, typename V>
class WeightedUndirectedGraph{
private:
	std::map<T, std::vector<std::pair<T,V>>> edges;

	// BOOL MAP FILL
	void fill_bool_map_mask(std::map<T, std::map<T, bool>>& visitedMatrix) {
		for (auto x : edges) {
			for (unsigned long long i = 0; i < x.second.size(); ++i) {
				visitedMatrix[x.first][x.second[i].first] = false;
			}
		}
	}

	void print_bool_map_mask(std::map<T, std::map<T, bool>>& visitedMatrix) {
		for (auto x : visitedMatrix) {
			std::cout << x.first << ": ";
			for (auto y : x.second) {
				std::cout << "[" << y.first << "|" << y.second << "], ";
			}
			std::cout << "\n";
		}
	}

	template<typename T>
	unsigned long long binary_search_index(T key, T value) {
		if (edges.count(key)) {
			auto& arr = edges[key];
			unsigned long long start = 0;
			unsigned long long end = arr.size() - 1;
			unsigned long long index;
			while (start<=end) {
				index = start + (end - start) / 2;
				auto& currentValue = arr[index].first;
				if (currentValue == value) {
					return index;
				}
				else if (currentValue < value) {
					start = index + 1;
				}
				else {
					end = index - 1;
				}
			}
			throw new std::exception("Element is not present in the array");
		}
		throw new std::exception("Invalid key");
	}

public:
	// CONSTRUCTORS
	WeightedUndirectedGraph() = delete;

	WeightedUndirectedGraph(std::vector<std::pair<std::vector<T>, V>> listOfWeightedEdges) {
		for (unsigned long long i = 0; i < listOfWeightedEdges.size(); ++i) {
			edges[listOfWeightedEdges[i].first[0]].push_back(std::pair<T, V>{listOfWeightedEdges[i].first[1], listOfWeightedEdges[i].second});
			edges[listOfWeightedEdges[i].first[1]].push_back(std::pair<T, V>{listOfWeightedEdges[i].first[0], listOfWeightedEdges[i].second});
		}

		for (auto& x : edges) {
			std::sort(x.second.begin(), x.second.end());
		}
	}

	// PRINTS
	void print_edges() {
		for (auto x : edges) {
			std::cout << x.first << ": ";
			ArrayFunctions::print_pair_array_first_elements(x.second);
			std::cout << "\n";
		}
	}

	void print_distances() {
		for (auto x : edges) {
			std::cout << x.first << ": ";
			ArrayFunctions::print_pair_array_second_elements(x.second);
			std::cout << "\n";
		}
	}

	void print_weighted_graph_separate() {
		print_edges();
		std::cout << "\n";
		print_distances();
	}

	void print_weigthed_graph() {
		for (auto x : edges) {
			std::cout << x.first << ": ";
			ArrayFunctions::print_pair_array(x.second);
			std::cout << "\n";
		}
	}


	// FUNCTIONS
	template <typename T>
	std::vector<T> find_shortest_path(T keyStart, T keyEnd) {
		if (edges.count(keyStart) && edges.count(keyEnd)) {
			std::map<T,bool> visited;
			std::queue<T> nodes;
			std::map<T,std::pair<T,V>> path;

			for (auto x : edges) {
				auto& val = x.first;
				path[val].first = 0;
				path[val].second = INFINITY;
				visited[val] = false;
			}

			path[keyStart].first = 0;
			path[keyStart].second = 0;
			nodes.push(keyStart);

			while (!nodes.empty()) {
				// save root in a variable
				auto & root = nodes.front();
				auto & arr = edges[root];

				if (!visited[root]) {
					for (unsigned long long i = 0; i < arr.size(); ++i) {
						// save each key of the roots in a variable
						auto key = arr[i].first;
						nodes.push(key);

						V sum = path[root].second + arr[i].second;
						if (path[key].second > sum) {
							path[key].first = root;
							path[key].second = sum;
						}
					}
				}

				visited[root] = true;
				nodes.pop();
			}

			for (auto x : path) {
				std::cout << x.first << ": [";
				std::cout << x.second.first << "|" << x.second.second << "]\n";
			}

			std::vector<T> final_path;
			T key = keyEnd;
			while (key != keyStart) {
				final_path.insert(final_path.begin(), key);
				key = path[key].first;
			}
			final_path.push_back(keyStart);

			return final_path;
		}
		return std::vector<T> {-1};
	}
};

int main() {
	UndirectedGraph<int> graph(std::vector<std::vector<int>>{ 
		{ 1, 2 },
		{ 0, 1 },
		{ 0, 3 },
		{ 1, 3 },
		{ 1, 4 },
		{ 0, 4 },
	});

	graph.print_graph();
	std::cout << "\n";

	/*
	WeightedUndirectedGraph<int, double> wGraph(
		std::vector<std::pair<std::vector<int>, double>>{
			{ { 1, 2 }, 0.5},
			{ { 0, 1 }, 1 },
			{ { 0, 3 }, 2 },
			{ { 1, 3 }, 3 },
			{ { 1, 4 }, 4 },
			{ { 0, 4 }, 2.5}
		}
	);
	*/

	WeightedUndirectedGraph<int, double> wGraph(
		std::vector<std::pair<std::vector<int>, double>>{
			{ { 1, 2 }, 7},
			{ { 1, 4 }, 12 },
			{ { 2, 4 }, 10 },
			{ { 2, 3 }, 2 },
			{ { 3, 4 }, 1 },
	}
	);

	wGraph.print_weighted_graph_separate();
	
	std::cout << "\n";

	std::vector<int> shortest_path = wGraph.find_shortest_path(1, 4);

	ArrayFunctions::print_array(shortest_path);

	return 0;
}
