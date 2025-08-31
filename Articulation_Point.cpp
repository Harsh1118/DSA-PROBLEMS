// Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnects the graph into 2 or more components and return it in sorted manner.
// Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

// Example 1:

// Input:

// Output:{1,4}
// Explanation: Removing the vertex 1 will
// discconect the graph as-

// Removing the vertex 4 will disconnect the
// graph as-

// Your Task:
// You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are no such vertices then returns a list containing -1.

// Expected Time Complexity: O(V + E)
// Expected Auxiliary Space: O(V)

// Constraints:
// 1 ≤ V ≤ 105

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void DFS(int node, int parent, vector<int> adj[], vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<bool> &artpoint, int &timer)
    {
        visited[node] = 1;

        disc[node] = low[node] = timer;

        int child = 0;

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neib = adj[node][j];

            if (neib == parent)
            {
                continue;
            }

            else if (visited[neib])
            {
                low[node] = min(low[node], disc[neib]);
            }

            else
            {
                child++;
                timer++;
                DFS(neib, node, adj, disc, low, visited, artpoint, timer);
                if (disc[node] <= low[neib] && parent != -1)
                {
                    artpoint[node] = 1;
                }

                low[node] = min(low[node], low[neib]);
            }
        }

        if (child > 1 && parent == -1)
        {
            artpoint[node] = 1;
        }
    }

    vector<int> articulationPoints(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> artpoint(V, 0);
        vector<int> disc(V);
        vector<int> low(V);
        vector<bool> visited(V, 0);
        int timer = 0;

        DFS(0, -1, adj, disc, low, visited, artpoint, timer);

        vector<int> ans;

        for (int i = 0; i < V; i++)
        {
            if (artpoint[i])
            {
                ans.push_back(i);
            }
        }

        if (ans.size() == 0)
        {
            ans.push_back(-1);
            return ans;
        }

        return ans;
    }
};