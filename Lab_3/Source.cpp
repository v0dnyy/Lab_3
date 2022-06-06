#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"

using namespace std;

int main()
{
    Graph<std::string, double> g;
    g.Add_Vertex("Samara");
    g.Add_Vertex("Saint-Peterburg");
    g.Add_Vertex("Moscow");
    g.Add_Vertex("Minsk");
    g.Add_Vertex("Kiev");
    g.Add_Vertex("Omsk");
    g.Add_Vertex("Vladivostok");
    g.Add_Edge("Samara", "Saint-Peterburg", 1740);
    g.Add_Edge("Moscow", "Saint-Peterburg", 780);
    g.Add_Edge("Samara", "Moscow", 1055);
    g.Add_Edge("Moscow", "Minsk", 1378);
    g.Add_Edge("Minsk", "Saint-Peterburg", 1100);
    g.Add_Edge("Minsk", "Kiev", 655);
    g.Add_Edge("Vladivostok", "Omsk", 5000);
    g.Add_Edge("Saint-Peterburg", "Vladivostok", 11987);

    g.Print();
    cout << "===========================" << endl;
    //g.BFS("Samara");
    cout << "===========================" << endl;
    g.Delete_Edge("Samara", "Saint-Peterburg");
    g.Delete_Edge("Minsk", "Saint-Peterburg");
    g.Print();
    cout << "===========================" << endl;
    try
    {
        g.Delete_Vertex("Kiev");
    }
    catch (const char* err)
    {
        cout << err << endl;
    }
    cout << "===========================" << endl;
    try {
        g.Delete_Vertex("Kiev");
    }
    catch (const char* err)
    {
        cout << err << endl;
    }
    g.Print();
    cout << "===========================" << endl;

    return 0;
}