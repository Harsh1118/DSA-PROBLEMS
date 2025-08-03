/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any 
cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from 
verticex u to v.

Examples:

Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 0], [2, 3]]

Output: true
Explanation: The diagram clearly shows a cycle 0 → 2 → 0
Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]

Output: false
Explanation: no cycle in the graph
Constraints:
1 ≤ V, E ≤ 105
u ≠ v

Expected Complexities
Time Complexity: O(V + E)
Auxiliary Space: O(V + E)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
  
  bool detectcycle(int node , vector<vector<int>>&adj , vector<bool>&path , vector<bool>&visited)
  {
      path[node] = 1;
      visited[node] = 1;
      
      for(int i = 0; i<adj[node].size(); i++)
      {
          if(path[adj[node][i]])
          {
              return 1;
          }
          
          if(!visited[adj[node][i]] && detectcycle(adj[node][i],adj,path,visited))
          {
              return 1;
          }
      }
      path[node]=0;
      return 0;
  }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(auto&edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<bool>path(V,0);
        vector<bool>visited(V,0);
        
        for(int i = 0; i<V; i++)
        {
            if(!visited[i] && detectcycle(i,adj,path,visited))
            {
                return 1;
            }
        }
        return 0;
    }
};