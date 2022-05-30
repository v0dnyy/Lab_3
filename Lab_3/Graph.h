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
	int Index(TVertex Temp_Vertex)
	{
		for (size_t i = 0; i < table.size(); i++)
		{
			if (table[i].data == Temp_Vertex) return table[i].id_v;
		}
		return -1;
	}
};
