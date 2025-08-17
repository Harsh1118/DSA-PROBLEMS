// You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

// Examples :

// Input: adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src=0
// Output: [0, 1, 2, 1, 2, 3, 3, 4, 4]
 
// Input: adj[][]= [[3], [3], [], [0, 1]], src=3
// Output: [1, 1, -1, 0]

// Input: adj[][]= [[], [], [], [4], [3], [], []], src=1
// Output: [-1, 0, -1, -1, -1, -1, -1] 
// Constraint:
// 1<=adj.size()<=104
// 0<=edges<=adj.size()-1

// Expected Complexities
// Time Complexity: O(V + E)
// Auxiliary Space: O(V)

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        vector<int>dist(adj.size(),-1);
        vector<bool>visited(adj.size(),0);
        
        queue<int>q;
        q.push(src);
        dist[src] = 0;
        visited[src] = 1;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(int j = 0; j<adj[node].size(); j++)
            {
                if(visited[adj[node][j]])
                {
                    continue;
                }
                
                visited[adj[node][j]]=1;
                q.push(adj[node][j]);
                dist[adj[node][j]] = dist[node] +1;
                
            }
        }
        return dist;
    }
};