// There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisites[][] tasks, for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
// Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
// Note: There may be multiple correct orders, you just need to return any one of them. If it is impossible to finish all tasks, return an empty array. Returning any correct order will give the output as true, whereas any invalid order will give the output false.

// Examples:

// Input: n = 2, prerequisites[][] = [[1, 0]]
// Output: true
// Explanation: Only possible order is [0, 1].
// Input: n = 4, prerequisites[][] = [[1, 0], [2, 0], [3, 1], [3, 2]]
// Output: true
// Explanation: There are a total of 4 tasks to pick. To pick task 3 you should have finished both tasks 1 and 2. Both tasks 1 and 2 should be pick after you finished task 0. So one correct task order is [0, 1, 2, 3]. Another correct ordering is [0, 2, 1, 3]. Returning any of these order will result in an output of true.
// Constraints:
// 1 ≤ n ≤ 105
// 0 ≤ prerequisites[i][0], prerequisites[i][1] < n
// All prerequisite pairs are unique
// prerequisites[i][0] ≠ prerequisites[i][1]
// Expected Complexities
// Time Complexity: O(n + m)
// Auxiliary Space: O(n + m)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findOrder(int n, vector<vector<int>> prerequisites)
    {
        // code here
        int p = prerequisites.size();
        vector<int> adj[n];
        vector<int> Indeg(n, 0);

        for (int i = 0; i < p; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            Indeg[prerequisites[i][0]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (!Indeg[i])
            {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int j = 0; j < adj[node].size(); j++)
            {
                Indeg[adj[node][j]]--;
                if (!Indeg[adj[node][j]])
                {
                    q.push(adj[node][j]);
                }
            }
        }

        vector<int> temp;
        return ans.size() == n ? ans : temp;
    }
};