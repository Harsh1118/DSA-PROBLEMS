/*
given a Directed Acyclic Graph (DAG) of V (0 to V-1) vertices and E edges represented as a 2D list of edges[][], 
where each entry edges[i] = [u, v] denotes a directed edge u -> v. Return the topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every 
directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned 
Topological sort is correct then the output will be true else false.

Examples:

Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5,2]]

Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]
Constraints:
2  ≤  V  ≤  5 x 103
1  ≤  E = edges.size()  ≤  min[105, (V * (V - 1)) / 2]

Expected Complexities
Time Complexity: O(V + E)
Auxiliary Space: O(V)*/



/*                                        TOPOLOGICAl SORT

  TOPOLOGICAL sorting for a DAG (Directed Acyclic Graph) is a linear ordering of vertices such that for every 
  directed edge  u->v the vertex u comes before v

*/


#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
  public:
  
  void DFS (int node , vector<vector<int>>&adj , vector<bool>&visited,stack<int>&s)
  {
      visited[node] = 1;
      
      for(int i = 0; i<adj[node].size(); i++)
      {
          if(!visited[adj[node][i]])
          {
              DFS(adj[node][i],adj,visited,s);
          }
      }
      s.push(node);
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V+1);
        for(auto&edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        vector<bool>visited(V,0);
        stack<int>s;
        
        for(int i = 0 ; i<V; i++)
        {
             if(!visited[i])
             {
                 DFS(i,adj,visited,s);
             }
        }
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};