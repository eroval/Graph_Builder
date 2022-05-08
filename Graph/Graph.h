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

	std::pair<int> nondijkstra(T root, T target) {
		std::map<T, bool> visited;
		std::stack<T> nodes;
		int Sum;
		bool set = false;


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
		make_weighted_if_neccessary(x, y, value);
		edges[x][y] = value;
	}

	void add_undirected(T x, T y, double value = 0) {
		make_weighted_if_neccessary(x, y, value);
		edges[x][y] = value;
		edges[y][x] = value;
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

	void shortest_path(T root, T target) const {
		if (weighted) {

		}
	}


	/*
	void shortest_path_unweighted(T root, T target) const{
		GraphFunctions::check_node_existence(this->edges, root);
		GraphFunctions::check_node_existence(this->edges, target);

		std::queue<T> nodes;
		if (this->edges.count(root) < 1) {
			throw std::exception("No such root");
		}
		if( this->edges.count(target))
		nodes.push(T)
	}

	void shortest_path_weighted() const{
		
	}
	*/
};

#endif 
