#include <iostream>
#include<vector>

template<typename TVertex, typename TEdge >
class Graph {
private:
	struct destination {
		int id_d;
		TVertex dest;
		TEdge edge;
	};
	struct vertex
	{
		int id_v;
		TVertex data;
		vector<destination> dest;
	};
	vector<vertex> table;
public:
	int Index(TVertex tmp_vertex)
	{
		for (size_t i = 0; i < table.size(); i++)
		{
			if (table[i].data == tmp_vertex) return table[i].id_v;
		}
		return -1;
	}
	void Add_Vertex(TVertex tmp_source) {
		if (Index(tmp_source) != -1) {
			vertex temp_vertex;
			temp_vertex.id_v = table.size();
			temp_vertex.data = tmp_source;
			table.push_back(temp_vertex);
		}
		else throw "That vertex already exists."
	};
	void Add_Edge(TVertex source, TVertex dest,TEdge Edge){
		if (Index(source) == -1) throw "Source not exist";
		if (Index(dest) == -1) throw "Destenation not exist";
		destination tmp_dest;
		tmp_dest.id_d = Index(dest);
		tmp_dest.dest = dest;
		tmp_dest.edge = Edge;
		table[Index(source)].dest.push_back(tmp_dest);
	}
};
