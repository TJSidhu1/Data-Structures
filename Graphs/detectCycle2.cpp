// Code to detect cycle in a directed graph
// We will represt the graph as a vector of edges
#include <iostream>
#include <vector>
using namespace std;

bool detectCylce(vector<vector<int>> edges, int num)
{
    vector<vector<int>> adjList(num);

    // creating an adjacency list
    for(int i=0; i< edges.size(); i++)
    {
       adjList[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(num, 0);

    for(int i=0; i < visited.size(); i++)
    {
        dfs(i, adjList, visited, st)
    }
}