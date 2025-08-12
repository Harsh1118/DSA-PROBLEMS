// There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do
// task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
// Given the total number of tasks N and a list of P prerequisite pairs, find if it is possible to finish all tasks.

// Examples:

// Input: N = 4, P = 3, prerequisites = [[1,0],[2,1],[3,2]]
// Output: Yes
// Explanation: To do task 1 you should have completed task 0, and to do task 2 you should have finished task 1,
// and to do task 3 you should have finished task 2. So it is possible.
// Input: N = 2, P = 2, prerequisites = [[1,0],[0,1]]
// Output: No
// Explanation: To do task 1 you should have completed task 0, and to do task 0 you should have finished task 1.
// So it is impossible.
// Constraints:
// 1 ≤ N ≤ 104
// 1 ≤ P ≤ 105

// Expected Complexities
// Time Complexity: O(N + P)
// Auxiliary Space: O(N + P)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
    {
        // Code here

        // Adjacency list creation

        vector<int> adj[N];
        vector<int> Indeg(N, 0);

        for (int i = 0; i < P; i++)
        {
            adj[prerequisites[i].second].push_back(prerequisites[i].first);
            Indeg[prerequisites[i].first]++;
        }

        //  Kahn's algo

        queue<int> q;
        for (int i = 0; i < N; i++)
        {
            if (!Indeg[i])
            {
                q.push(i);
            }
        }

        int count = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            count++;

            for (int j = 0; j < adj[node].size(); j++)
            {
                Indeg[adj[node][j]]--;
                if (!Indeg[adj[node][j]])
                {
                    q.push(adj[node][j]);
                }
            }
        }

        return count == N;
    }
};