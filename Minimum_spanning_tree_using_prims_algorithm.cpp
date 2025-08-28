// Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is provided as a list of edges, where each edge is represented as [u, v, w], indicating an edge between vertex u and vertex v with edge weight w.

// Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]

// Output: 4
// Explanation:

// The Spanning Tree resulting in a weight
// of 4 is shown above.
// Input: V = 2, E = 1, Edges = [[0 1 5]]

// Output: 5
// Explanation: Only one Spanning Tree is possible which has a weight of 5.
// Constraints:
// 2 ≤ V ≤ 1000
// V-1 ≤ E ≤ (V*(V-1))/2
// 1 ≤ w ≤ 1000
// The graph is connected and doesn't contain self-loops & multiple edges.

// Expected Complexities

// Time Complexity: O((V + E) log V)
// Auxiliary Space: O(V + E)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        // code here

        vector<vector<pair<int, int>>> adj(V);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> p;

        vector<bool> Ismst(V, 0);
        vector<int> parent(V);

        int cost = 0;

        p.push({0, {0, -1}});

        while (!p.empty())
        {
            int wt = p.top().first;
            int node = p.top().second.first;
            int par = p.top().second.second;
            p.pop();

            if (!Ismst[node])
            {
                Ismst[node] = 1;

                cost += wt;

                parent[node] = par;

                for (int j = 0; j < adj[node].size(); j++)
                {
                    if (!Ismst[adj[node][j].first])
                    {
                        p.push({adj[node][j].second, {adj[node][j].first, node}});
                    }
                }
            }
        }
        return cost;
    }
};