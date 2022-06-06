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
