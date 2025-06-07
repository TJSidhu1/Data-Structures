// Code to detect cycle in an undirected graph
// We will represt the graph as a vector of edges
#include <vector>
using namespace std;
bool detectCycle(vector<vector<int>> edges, int n)
{
    // creating an adjacency list from the edge list
    vector<vector<int>> adjList(n);
    for(int i=0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(n,0);

    for(int i=0; i< visited.size(); i++)
    {
        if(visited[i] == false)
           return dfs(i, -1, visited, adjList);
    }

    return true;   
 
}

bool dfs(int i, int parent, vector<bool> &visited, vector<vector<int>>& adjList)
{
    
   for(int j=0; j< adjList[i].size(); j++)
   {
      if(i == adjList[i][j])
      {
        continue;
      }
      else if(visited[j] != 1)
      {
         dfs(adjList[i][j], i, visited, adjList);
      }
      else
          return false;
      
   }
}

