#include <vector>
#include <string>
#include <iostream>
#include <queue>

using namespace std;

struct Edge{
	string dest;
	double length;
	Edge(const Edge& rhs){
		this->dest = rhs.dest;
		this->length = rhs.length;
	}
	Edge& operator =(const Edge& rhs){
		if (this == &rhs) return *this;
		this->dest = rhs.dest;
		this->length = rhs.length;
		return *this;
	}
	Edge() : dest(" "), length(-1) {}
	Edge(const string& d, const double& l) :length(l), dest(d) {}
	operator double() const {
		return length;
	}
};
struct Vertex{
	string id;
	size_t amount;
	bool colour;
	Vertex(){
		id = " ";
		amount = 0;
		colour = false;
	}
	Vertex(const Vertex& rhs){
		this->id = rhs.id;
		this->amount = rhs.amount;
		this->colour = rhs.colour;
	}
	Vertex& operator=(const Vertex& rhs){
		if (this == &rhs) return *this;
		this->id = rhs.id;
		this->amount = rhs.amount;
		this->colour = rhs.colour;
		return *this;
	}
	Vertex(const string& str, const size_t& am) : id(str), amount(am), colour(0) {}
};
template<>
struct equal_to<Vertex> {
	size_t operator()(const Vertex& v1, const Vertex& v2) {
		return((v1.id == v2.id) && (v1.amount == v2.amount));
	}
};
template <typename TVertex, typename TEdge, typename equal = equal_to<Vertex>>
class Graph {
	vector<vector<TEdge>> edge;
	vector<TVertex> vertex_table;
	size_t count;
	bool check(vector<TVertex>& tmp, const string& str) const {
		for (size_t i = 0; i < tmp.size(); ++i) {
			if (str == tmp[i].id) return true;
		}
		return false;
	}
	int checker(const string& str) const {
		for (size_t i = 0; i < vertex_table.size(); ++i) {
			if (str == vertex_table[i].id) return i;
		}
		return -1;
	}
public:
	int Get_ID(const TVertex& rhs) const {
		equal compare;
		for (size_t i = 0; i < vertex_table.size(); ++i)
		{
			if (compare(rhs, vertex_table[i]))
				return i;
		}
		return -1;
	}
	int Get_ID(const string& rhs) const {
		for (size_t i = 0; i < vertex_table.size(); ++i)
		{
			if (vertex_table[i].id == rhs)
				return i;
		}
		return -1;
	}
	Graph() {
		count = 0;
	}
	bool findVertex(const TVertex& f) const {
		equal compare;
		for (auto it : vertex_table) {
			if (compare(it, f)) return true;
		}
		return false;
	}
	void addVertex(const TVertex& newVertex)
	{
		if (findVertex(newVertex) == true) return;
		vertex_table.push_back(newVertex);
		vector<TEdge> tmp(0);
		edge.push_back(tmp);
		count++;
	}
	void deleteVertex(const TVertex& target) {
		equal compare;
		int ind = -1;
		string temp;
		for (size_t i = 0; i < vertex_table.size(); ++i) {
			if (compare(vertex_table[i], target)) {
				ind = i;
				temp = vertex_table[i].id;
				vertex_table.erase(vertex_table.begin() + i);
				break;
			}
		}
		if (ind == -1) return;
		edge[ind].erase(edge[ind].begin(), edge[ind].end());
		for (size_t i = 0; i < edge.size(); ++i) {
			for (size_t j = 0; j < edge[i].size(); ++j) {
				if (edge[i][j].dest == temp) {
					edge[i].erase(edge[i].begin() + j);
				}
			}
		}
		--count;
	}
	void addEdge(const TVertex& src, const TVertex& dst, const TEdge& newEdge) {
		if (findVertex(src) == false || findVertex(dst) == false) return;
		equal compare;
		for (size_t i = 0; i < vertex_table.size(); ++i) {
			if (compare(src, vertex_table[i])) {
				edge[i].push_back(newEdge);
				return;
			}
		}
	}
	void deleteEdge(const TVertex& src, const TVertex& dst) {
		if (findVertex(src) == false || findVertex(dst) == false) return;
		int ind = -1;
		equal compare;
		for (size_t i = 0; i < vertex_table.size(); ++i) {
			if (compare(vertex_table[i], src)) {
				ind = i;
				break;
			}
		}
		for (size_t i = 0; i < edge[ind].size(); ++i) {
			if (edge[ind][i].dest == dst.id) {
				edge[ind].erase(edge[ind].begin() + i);
			}
		}
	}
	void BFS(const TVertex& from) {
		if (Get_ID(from) == -1) throw "That city is nit exist";
		for (auto elem : vertex_table)
		{
			elem.colour = false;
		}
		queue<Vertex> q;
		equal compare;
		Vertex s;
		for (size_t i = 0; i < vertex_table.size(); ++i) {
			if (compare(vertex_table[i], from)) {
				s = vertex_table[i];
				vertex_table[i].colour = true;
				break;
			}
		}
		q.push(s);
		while (!q.empty()) {
			Vertex u = q.front();
			q.pop();
			int t = Get_ID(u);
			for (auto elem : edge[t])
			{
				Vertex& v = vertex_table[Get_ID(elem.dest)];
				if (v.colour == false)
				{
					v.colour = true;
					q.push(v);
				}
			}
			cout << u.id << endl;
		}
	}
};
