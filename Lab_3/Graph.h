#include <iostream>
#include<vector>

template<typename TVertex, typename TEdge >
class Graph {
private:
	struct destination {
		int id;
		TVertex dest;
		TEdge edge;
	};
	struct vertex
	{
		int id;
		TVertex source;
		vector<destination> dest;
	};
	vector<vertex> table;
};
