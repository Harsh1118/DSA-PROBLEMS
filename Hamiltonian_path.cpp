// Given an undirected graph with n vertices and m edges, your task is to determine if a Hamiltonian path exists in the graph.

// A Hamiltonian path is a path in an undirected graph that visits each vertex exactly once.

// You are provided the following:


// n: The number of vertices in the graph.
// m: The number of edges in the graph.
// edges[][]: A 2D list where each element edges[i] represents an edge between two vertices edges[i][0] and edges[i][1]. 
// Examples:

// Input: n = 4, m = 4
// edges[][]= { {1,2}, {2,3}, {3,4}, {2,4} }
// Output: 1 
// Explanation: There is a hamiltonian path: 1 -> 2 -> 3 -> 4 
// Input: n = 4, m = 3 
// edges[][] = { {1,2}, {2,3}, {2,4} } 
// Output: 0 
// Explanation: It can be proved that there is no hamiltonian path in the given graph.
// Constraints:
// 1 ≤ n ≤ 10
// 1 ≤ m ≤ 15
// Size of edges[i] is 2
// 1 ≤ edges[i][0],edges[i][1] ≤ n

// Expected Complexities
// Time Complexity: O(n!)
// Auxiliary Space: O(n + m)

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
  
  bool DFS(int node , vector<vector<int>>&adj,vector<bool>&visited,int &count , int N)
  {
      visited[node] = 1;
      count++;
      
      if(count==N)
      {
          return 1;
      }
      
      for(int j = 0; j<adj[node].size(); j++)
      {
          if(!visited[adj[node][j]] && DFS(adj[node][j],adj,visited,count,N))
          {
              return 1;
          }
      }
      visited[node] = 0;
      count--;
      return 0;
  }
    bool check(int n, int m, vector<vector<int>> edges) {
        // code here
        vector<vector<int>>adj(n);
        for(int i = 0; i<m; i++)
        {
            adj[edges[i][0]-1].push_back(edges[i][1]-1);
            adj[edges[i][1]-1].push_back(edges[i][0]-1);
        }
        
        vector<bool>visited(n,0);
        int count = 0;
        
        for(int i = 0; i<n; i++)
        {
            if(DFS(i,adj,visited,count,n))
            {
                return 1;
            }
        }
        return 0;
    }
};
