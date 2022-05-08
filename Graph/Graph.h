#ifndef GRAPH_H
#define GRAPH_H


#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>

template <typename T = int>
class Graph {
private:
	std::unordered_map<T, std::unordered_map<T, double>> edges;
	bool weighted=false;

	void make_weighted_if_neccessary(T x, T y, double value) {
		if (weighted || value == 0) return;
		weighted = true;
	}

	void add_pair(std::vector<int>& x, bool bidirected) {
		if (x.size() > 2) {
			if (bidirected) {
				this->add_undirected(x[0], x[1], x[2]);
			}
			else this->add_directed(x[0], x[1], x[2]);
		}
		else {
			if (bidirected) {
				this->add_undirected(x[0], x[1]);
			}
			else this->add_directed(x[0], x[1]);
		}
	}
	
	void check_node_existence(T target) {
		if (this->edges.count(target) < 1) {
			throw std::exception("No such node.");
		}
	}

	std::vector<T> nondijkstra_path(T root, T target) {
		std::unordered_map<T, std::unordered_map<T,bool>> visited;
		std::vector<T> nodes;
		std::vector<std::vector<T>> arr;
		bool set = false;

		// set bool mask map
		for (auto& x : this->edges) {
			for (auto& y : x.second) {
				visited[x.first][y.first] = false;
			}
		}

		for (auto& y : this->edges[root]) {
			visited[y.first][root] = true;
		}

		for (auto& x : visited) {
			std::cout << x.first << ": ";
			for (auto& y : x.second) {
				std::cout << y.first << "|" << y.second << " ";
			}
			std::cout << "\n";
		}

		nodes.push_back(root);
		while (!nodes.empty()) {
			for (auto x = edges[nodes.back()].begin(); x != edges[nodes.back()].end(); x++) {
				if (!visited[nodes.back()][x->first]) {
					visited[nodes.back()][x->first] = true;
					if (x->first == target) {
						set = true;
						nodes.push_back(target);
						arr.push_back(nodes);
						nodes.pop_back();
						break;
					}
					nodes.push_back(x->first);
					x = this->edges[nodes.back()].begin();
				}
			}
			nodes.pop_back();
		}


		if (!set) {
			return std::vector<int>{-1};
		}

		unsigned long long indexOfSmallestVector = 0;
		unsigned long long sizeOfSmallestVector = arr[0].size();

		for (unsigned long long i = 0; i < arr.size(); i++) {
			if (arr[i].size() < sizeOfSmallestVector) {
				indexOfSmallestVector = i;
				sizeOfSmallestVector = arr[i].size();
			}
		}

		return arr[indexOfSmallestVector];
	}

public:
	// CONSTRUCTORS
	Graph() = delete;

	Graph(std::vector<std::pair<std::vector<int>, bool>> listOfEdges) {
		this->add_edges(listOfEdges);
	}


	void add_edges(std::vector<std::pair<std::vector<int>, bool>> listOfEdges) {
		for (unsigned long long i = 0; i < listOfEdges.size(); i++) {
			this->add_pair(listOfEdges[i].first, listOfEdges[i].second);
		}
	}

	void add_directed(T x, T y, double value = 0){
		if (x != y) {
			make_weighted_if_neccessary(x, y, value);
			edges[x][y] = value;
		}
	}

	void add_undirected(T x, T y, double value = 0) {
		if (x != y) {
			make_weighted_if_neccessary(x, y, value);
			edges[x][y] = value;
			edges[y][x] = value;
		}
	}

	// PRINTS
	void print_graph() {
		// std::unordered_map<T, std::unordered_map<T, double>> edges;
		for (auto& x : this->edges) {
			std::cout << x.first << ":";
			for (auto& y : x.second) {
				std::cout << " " << y.first;
				if (this->weighted) std::cout << "|" << y.second << " ";
				else std::cout << " ";
			}
			std::cout << "\n";
		}
	}

	void print_sorted_graph() {
		std::map<T, std::map<T, double>> graph_copy_sorted;

		for (auto& x : this->edges) {
			for (auto& y : x.second) {
				graph_copy_sorted[x.first][y.first] = y.second;
			}
		}

		for (auto& x : graph_copy_sorted) {
			std::cout << x.first << ":";
			for (auto& y : x.second) {
				std::cout << " " << y.first;
				if (this->weighted) std::cout << "|" << y.second << " ";
				else std::cout << " ";
			}
			std::cout << "\n";
		}
	}

	void print_shortest_path(T root, T target) {
		this->check_node_existence(root);
		this->check_node_existence(target);
		std::vector<T> path;

		if (weighted) {

		}
		else {
			path = nondijkstra_path(root, target);
		}


		for (unsigned long long i = 0; i < path.size(); i++) {
			std::cout << path[i] << " ";
		}
		std::cout << "\n";
	}
};

#endif 
