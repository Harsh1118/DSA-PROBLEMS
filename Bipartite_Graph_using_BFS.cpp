/*Given a Graph with V vertices (Numbered from 0 to V-1) and E edges. Check whether the graph is bipartite or not.

A bipartite graph can be colored with two colors such that no two adjacent vertices share the same color. 
This means we can divide the graph’s vertices into two distinct sets where:

All edges connect vertices from one set to vertices in the other set.
No edges exist between vertices within the same set.
Examples:

Input: V = 3, edges[][] = [[0, 1], [1,2]]
Bipartite-Graph
Output: true
Explanation: The given graph can be colored in two colors so, it is a bipartite graph.
Input: V = 4, edges[][] = [[0, 3], [1, 2], [3, 2], [0, 2]]




Output: false 
Explanation: The given graph cannot be colored in two colors such that color of adjacent vertices differs. 
Constraints:
1 ≤ V ≤ 2 * 105
1 ≤ edges.size() ≤ 105
1 ≤ edges[i][j] ≤ 105

Expected Complexities
Time Complexity: O(V + E)
Auxiliary Space: O(V)
*/


/*                                         BIPARTITE GRAPH 

It is a Graph in which the vertices can be divided into two disjoint sets such that no two vertices 
within the same set are adjacent. In other words it is a graph in which every edge connects a vertex of 
one set to a vertex of other set.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

//  using BFS

class Solution {
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>>adj(V);
        for(auto&edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>color(V,-1);
        queue<int>q;
        for(int i = 0; i<V; i++)
        {
            if(color[i]==-1)
            {
                q.push(i);
                color[i]=0;
                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();
                    for(int j = 0; j<adj[node].size(); j++)
                    {
                        if(color[adj[node][j]]==-1)
                        {
                            color[adj[node][j]]=(color[node]+1)%2;
                            q.push(adj[node][j]);
                            
                        }
                        else
                        {
                            if(color[node]==color[adj[node][j]])
                            {
                                return 0;
                                
                            }
                            
                        }
                        
                    }
                    
                }
            }
        }
        return 1;
    }
};