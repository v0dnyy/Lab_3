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
			vertex new_vertex;
			new_vertex.id_v = table.size();
			new_vertex.data = tmp_source;
			table.push_back(tmp_source);
		}
		else throw "That vertex already exists."
	};

};
