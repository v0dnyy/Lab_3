#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename TVertex, typename TEdge>
class Graph {
private:
	struct destination {
		TVertex dest;
		TEdge edge;
		destination(const TEdge& e, const TVertex& v) : edge(e), dest(v) {}
		destination (const destination& d){
			this->edge = d.edge;
			this->dest = d.dest;
		}
	};
	struct vertex
	{
		int index;
		TVertex data; 
		vector<destination> dest_list;
		vertex( const int& idx, const TVertex& source) : index(idx), data(source) {}
		vertex(const vertex& v){
			this->index = v.index;
			this->data = v.data;
			this->dest_list = v.dest_list;
		}
	};
	vector<vertex> table;
public:
	int Index(TVertex v){
		for (size_t i = 0; i < table.size(); i++){
			if (table[i].data == v) return table[i].index;
		}
		return -1;
	}
	void Add_Vertex(TVertex v) {
		if (Index(v) < 0 ) {
			vertex temp_vertex(table.size(), v);
			table.push_back(temp_vertex);
		}
		else throw "That vertex already exists.";
	};
	void Add_Edge(const TVertex& source, const TVertex& dest, const TEdge& edge){
		if (Index(source) == -1) throw "Source not exist";
		if (Index(dest) == -1) throw "Destenation not exist";
		int index_destination = Index(dest);
		destination tmp_dest(edge, dest);
		table[Index(source)].dest_list.push_back(tmp_dest);
	}
	void Delete_Edge(const TVertex& source, const TVertex& dest)
	{
		int index_source = Index(source);
		int index_destination = Index(dest);
		if (index_source * index_destination < 0) { throw "The vetrtex is not exists"; }
		for (size_t i = 0; i < table[index_source].dest_list.size() - 1; i++)
		{
			if (table[index_source].dest_list[i].dest == dest)
			{
				for (size_t j = i; j < table[index_source].dest_list.size() - 1; j++)
				{
					table[index_source].dest_list[j] = table[index_source].dest_list[j + 1];
				}
				table[index_source].dest_list.pop_back();
			}
		}
	}
	void Delete_Vertex(const TVertex& target) {
		int target_index = Index(target);
		if (target_index == -1) throw "That vertex is not exists.";
		for (size_t i = target_index; i < table.size()-1; ++i) {
			table[i] = table[i + 1];
		}
		table.pop_back();
		for (size_t i = 0; i < table.size(); ++i) {
			for (size_t j = 0; j < table[i].dest_list.size(); j++) {
				if (table[i].dest_list[j].dest == target) {
					for (size_t k = j; k < table[i].dest_list.size() - 1; k++)
					{
						table[i].dest_list[k] = table[i].dest_list[k + 1];
					}
					table[i].dest_list.pop_back();

				}
			}
		}
	}
	void Print()
	{
		for (size_t i = 0; i < table.size(); i++)
		{
			cout << "From ";
			cout << table[i].data;
			cout << " to ";
			for (size_t j = 0; j < table[i].dest_list.size(); j++)
			{
				cout << table[i].dest_list[j].dest;
				cout << " by ";
				cout << table[i].dest_list[j].edge;
				if (j != table[i].dest_list.size() - 1)
				{
					cout << ", ";
				}
			}
			cout << endl;
		}
	}

};
