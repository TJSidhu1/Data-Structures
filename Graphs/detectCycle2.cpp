// Code to detect cycle in a directed graph
// We will represt the graph as a vector of edges
#include <iostream>
#include <vector>
using namespace std;

bool dfs(int i, vector<vector<int>> & adjList, vector<bool> & visited, vector<bool> &loopVisited)
{
    visited[i] = true;
    loopVisited[i] = true;
    for(int j=0; j < adjList[i].size(); j++)
    {
        if(loopVisited[adjList[i][j]] == false)
        {
               if(dfs(adjList[i][j], adjList, visited, loopVisited))
                  return true;   
        }
                    
           else
               return true;  
    }
    loopVisited[i] = false;
    return false;
}

bool detectCycle(vector<vector<int>> edges, int num)
{
    vector<vector<int>> adjList(num);

    // creating an adjacency list
    for(int i = 0; i < edges.size(); i++)
    {
       adjList[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(num, 0);
    vector<bool> loopVisited(num, 0);
    for(int i=0; i < visited.size(); i++)
    {
        if(dfs(i, adjList, visited, loopVisited))
           return true;
    }

    return false;
}

int main()
{
    vector<vector<int>> edges = {
        {0,1},
        {1,2},
        {2,5},           // for no cycle
        // {5,2},             // for creating a cycle
        {2,6},
        {6,5},
        {3,4},
        {4,5}

    };
     

    if(detectCycle(edges, 7))
       cout << "Cycle detected";

    else
      cout << "No cycle detected in the given graph" ;  

  
   return 0;   

}