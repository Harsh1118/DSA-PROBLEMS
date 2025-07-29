/*
Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], 
where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether 
the graph contains a cycle or not.

Examples:

Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
 
No cycle in the graph.
Constraints:
1 ≤ V ≤ 105
1 ≤ E = edges.size() ≤ 105

Expected Complexities
Time Complexity: O(V + E)
Auxiliary Space: O(V)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
  
  bool cycledetect(int node , int parent , vector<vector<int>>& adj , vector<bool>&visited)
  {
      visited[node] = 1;
      
      for(int i = 0; i<adj[node].size(); i++)
      {
          if(parent == adj[node][i])
          {
              continue;
          }
          
          if(visited[adj[node][i]])
          {
              return 1;
          }
          
          if(cycledetect(adj[node][i],node,adj,visited))
          {
              return 1;
          }
      }
      return 0;
  }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
       vector<vector<int>> adj(V + 1);  // use V+1 if nodes are 1-based
       for (auto& edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);  // Undirected graph
        }
        

        vector<bool>visited(V,0);
        
        for(int i = 0; i<V; i++)
        {
            if(!visited[i] && cycledetect(i,-1,adj,visited))
            {
                return 1;
            }
        }
        return 0;
    }
};