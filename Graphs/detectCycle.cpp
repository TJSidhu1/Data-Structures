// Code to detect cycle in an undirected graph
// We will represt the graph as a vector of edges
#include <vector>
#include <iostream>
using namespace std;


bool dfs(int i, int parent, vector<bool> &visited, vector<vector<int>>& adjList)
{

    visited[i] = true;
    
   for(int j=0; j < adjList[i].size(); j++)
   {
      if(adjList[i][j] == parent)
      {
        continue;
      }
      else if(visited[adjList[i][j]] != 1)
      {
        return dfs(adjList[i][j], i, visited, adjList);
      }
      else
          return true;
      
   }
   
}


bool detectCycle(vector<vector<int>> edges, int n)
{
    // creating an adjacency list from the edge list
    vector<vector<int>> adjList(n);
    for(int i=0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back(edges[i][1]);
        adjList[edges[i][1]].push_back(edges[i][0]);
    }

    vector<bool> visited(n,0);

    for(int i = 0; i < visited.size(); i++)
    {
        if(visited[i] == false)
           if( dfs(i, -1, visited, adjList))
              return true; 
    }

    return false;   
 
}



int main()
{
    vector<vector<int>> edges = {
        {0,2},
        {2,1},
        // {3,4},
        // {4,5}
        // ,{5,3}
    };

   cout <<  detectCycle(edges, 3);
}

