#include <iostream>
#include <string>
#include "Graph.h"

int main() {
	Graph<Vertex, Edge> g;
	g.addVertex(Vertex("New York", 8336817));
	g.addVertex(Vertex("Los Angeles", 3979576));
	g.addVertex(Vertex("Chicago", 2693976));
	g.addVertex(Vertex("Houston", 2320268));
	g.addVertex(Vertex("Phoenix", 1680992));
	g.addVertex(Vertex("Philadelphia", 1584064));
	g.addVertex(Vertex("San Antonio", 1547253));
	g.addVertex(Vertex("Dallas", 1343573));
	g.addVertex(Vertex("Austin", 978908));
	g.addEdge(Vertex("New York", 8336817), Vertex("Los Angeles", 3979576), Edge("Los Angeles", 500));
	g.addEdge(Vertex("New York", 8336817), Vertex("Chicago", 2693976), Edge("Chicago", 600));
	g.addEdge(Vertex("New York", 8336817), Vertex("Houston", 2320268), Edge("Houston", 750));
	g.addEdge(Vertex("Los Angeles", 3979576), Vertex("Phoenix", 1680992), Edge("Phoenix", 650));
	g.addEdge(Vertex("Los Angeles", 3979576), Vertex("San Antonio", 1547253), Edge("San Antonio", 300));
	g.addEdge(Vertex("Philadelphia", 1584064), Vertex("New York", 8336817), Edge("New York", 250));
	g.addEdge(Vertex("Philadelphia", 1584064), Vertex("Houston", 2320268), Edge("Houston", 140));
	g.addEdge(Vertex("Philadelphia", 1584064), Vertex("San Antonio", 1547253), Edge("San Antonio", 150));
	g.addEdge(Vertex("Phoenix", 1680992), Vertex("Los Angeles", 3979576), Edge("Los Angeles", 444));
	g.addEdge(Vertex("Phoenix", 1680992), Vertex("Chicago", 2693976), Edge("Chicago", 800));
	g.addEdge(Vertex("Phoenix", 1680992), Vertex("San Antonio", 1547253), Edge("San Antonio", 700));
	g.addEdge(Vertex("San Antonio", 1547253), Vertex("Chicago", 2693976), Edge("Chicago", 820));
	g.addEdge(Vertex("San Antonio", 1547253), Vertex("New York", 8336817), Edge("New York", 958));
	g.addEdge(Vertex("Chicago", 2693976), Vertex("Houston", 2320268), Edge("Houston", 344));
	g.addEdge(Vertex("Dallas", 1343573), Vertex("New York", 8336817), Edge("New York", 250));
	g.addEdge(Vertex("Dallas", 1343573), Vertex("Chicago", 2693976), Edge("Chicago", 555));
	g.addEdge(Vertex("Dallas", 1343573), Vertex("Philadelphia", 1584064), Edge("Philadelphia", 333));
	g.addEdge(Vertex("Houston", 2320268), Vertex("New York", 8336817), Edge("New York", 222));
	g.addEdge(Vertex("Houston", 2320268), Vertex("Dallas", 1343573), Edge("Dallas", 111));
	g.addEdge(Vertex("Austin", 978908), Vertex("Dallas", 1343573), Edge("Dallas", 146));
	g.deleteEdge(Vertex("Austin", 978908), Vertex("Dallas", 1343573));
	g.print();
	//cout << g.bfs(Vertex("Austin", 978908), Vertex("Dallas", 1343573));
	//vector<Vertex>path = g.dijkstra(Vertex("Temp", 5), Vertex("Houston", 2320268));
	try
	{
		g.BFS(Vertex("San Antonio", 1547253));
	}
	catch (const char* g)
	{
		cout << g;
	}
}