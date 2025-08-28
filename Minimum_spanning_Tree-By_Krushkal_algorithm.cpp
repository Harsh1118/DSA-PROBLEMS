// Here we dont sort edges directly beacuse the time comlexity for worst will remain ame in both case (if we do sorting,
// or use Priority queue) ,but when we talk about the best case , it may be happen by using priority queue , we will
// get our answer in the first V-1 edges , so we dont need to solve full adjacency list

// best case - VlogV + E

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
    int Findparent(int u, vector<int> &parent)
    {
        if (u == parent[u])
        {
            return u;
        }

        return parent[u] = Findparent(parent[u], parent);
    }

    void UnionbyRank(int u, int v, vector<int> &parent, vector<int> &rank)
    {
        int pu = Findparent(u, parent);
        int pv = Findparent(v, parent);

        if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }

        else if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }

        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

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

        vector<pair<int, pair<int, int>>> temp;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                temp.push_back({adj[i][j].second, {i, adj[i][j].first}});
            }
        }

        vector<int> parent(V);
        vector<int> rank(V, 0);

        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq(temp.begin(), temp.end());

        int cost = 0;
        int edge = 0;

        while (!pq.empty())
        {
            int wt = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();

            if (Findparent(u, parent) != Findparent(v, parent))
            {
                cost += wt;
                UnionbyRank(u, v, parent, rank);
                edge++;
            }
            if (edge == V - 1)
            {
                break;
            }
        }

        return cost;
    }
};