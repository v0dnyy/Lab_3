#include <iostream>
#include<vector>
#include <algorithm>

template<typename TVertex, typename TEdge >
class Graph {
private:
	struct destination {
		TVertex dest;
		TEdge edge;
		destination(const TEdge& e, const TVertex& v) : edge(e), destination_vertex(v) {}
		destination(const destination& d){
			this->edge = d.edge;
			this->destination_vertex = d.destination_vertex;
		}
	};
	struct vertex
	{
		int index;
		TVertex data;
		vector<destination> dest_list;
		vertex(const unsigned& idx, const TVertex& source) : index(idx), source_vertex(source) {}
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
			if (table[i].data == v) return table[i].id_v;
		}
		return -1;
	}
	void Add_Vertex(TVertex v) {
		if (Index(v) != -1) {
			vertex temp_vertex(table.size(), v);
			table.push_back(temp_vertex);
		}
		else throw "That vertex already exists."
	};
	void Add_Edge(TVertex source, TVertex dest,TEdge edge){
		if (Index(source) == -1) throw "Source not exist";
		if (Index(dest) == -1) throw "Destenation not exist";
		int index_destination = Index(dest);
		destination tmp_dest(edge, dest);
		table[Index(source)].dest_list.push_back(tmp_dest);
	}
	void Delete_Edge(TVertex source, TVertex dest)
	{
		int index_source = Index(source);
		int index_destination = Index(dest);
		if (index_source * index_destination < 0) { throw "The vetrtex is not exists"; }
		for (size_t i = 0; i < table.[index_source].dest_list.size(); i++)
		{
			if (table.[index_source].dest_list.[i].dest == dest)
			{
				for (size_t j = i; j < table[index_source].dest_list.size() - 1; j++)
				{
					table[index_source].dest_list.[j] = table.at[index_source].dest_list.at[j + 1];
				}
				table[index_source].dest_list.pop_back();
			}
		}
	}

};
