// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.

// Example 1:

// Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
// Output: [[1,3]]
// Explanation: [[3,1]] is also accepted.
// Example 2:

// Input: n = 2, connections = [[0,1]]
// Output: [[0,1]]

// Constraints:

// 2 <= n <= 105
// n - 1 <= connections.length <= 105
// 0 <= ai, bi <= n - 1
// ai != bi
// There are no repeated connections.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void DFS(int node, int parent, vector<vector<int>> &adj, vector<int> &disc, vector<int> &low, vector<bool> &visited, vector<vector<int>> &bridges, int &count)
    {
        disc[node] = low[node] = count;

        visited[node] = 1;

        for (int j = 0; j < adj[node].size(); j++)
        {
            int neib = adj[node][j];

            if (neib == parent)
            {
                continue;
            }

            else if (visited[neib])
            {
                low[node] = min(low[node], low[neib]);
            }

            else
            {
                count++;
                DFS(neib, node, adj, disc, low, visited, bridges, count);

                if (low[neib] > disc[node])
                {
                    vector<int> temp;
                    temp.push_back(node);
                    temp.push_back(neib);
                    bridges.push_back(temp);
                }
                low[node] = min(low[node], low[neib]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {

        vector<vector<int>> adj(n);
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<vector<int>> bridges;
        vector<int> disc(n);
        vector<int> low(n);

        vector<bool> visited(n, 0);
        int count = 0;

        DFS(0, -1, adj, disc, low, visited, bridges, count);

        return bridges;
    }
};