/*
Given a connected undirected graph containing V vertices represented by a 2-d adjacency list adj[][], 
where each adj[i] represents the list of vertices connected to vertex i. Perform a Depth First Search (DFS) 
traversal starting from vertex 0, visiting vertices from left to right as per the given adjacency list, and 
return a list containing the DFS traversal of the graph.

Note: Do traverse in the same order as they are in the given adjacency list.

Examples:

Input: adj[][] = [[2, 3, 1], [0], [0, 4], [0], [2]]

Output: [0, 2, 4, 3, 1]
Explanation: Starting from 0, the DFS traversal proceeds as follows:
Visit 0 → Output: 0 
Visit 2 (the first neighbor of 0) → Output: 0, 2 
Visit 4 (the first neighbor of 2) → Output: 0, 2, 4 
Backtrack to 2, then backtrack to 0, and visit 3 → Output: 0, 2, 4, 3 
Finally, backtrack to 0 and visit 1 → Final Output: 0, 2, 4, 3, 1
Input: adj[][] = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]

Output: [0, 1, 2, 3, 4]
Explanation: Starting from 0, the DFS traversal proceeds as follows: 
Visit 0 → Output: 0 
Visit 1 (the first neighbor of 0) → Output: 0, 1 
Visit 2 (the first neighbor of 1) → Output: 0, 1, 2 
Visit 3 (the first neighbor of 2) → Output: 0, 1, 2, 3 
Backtrack to 2 and visit 4 → Final Output: 0, 1, 2, 3, 4
Constraints:
1 ≤ V = adj.size() ≤ 104
1 ≤ adj[i][j] ≤ 104

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
  
  void DFS(int node, vector<vector<int>>& adj , vector<int>&ans , vector<bool>& visited)
  {
      visited[node] = 1;
      ans.push_back(node);
      
      for(int j = 0; j<adj[node].size(); j++)
      {
          if(!visited[adj[node][j]])
          {
              DFS(adj[node][j],adj,ans,visited);
          }
      }
  }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v = adj.size();
        vector<bool>visited(v,0);
        vector<int>ans;
        DFS(0,adj,ans,visited);
        
        return ans;
    }
};
