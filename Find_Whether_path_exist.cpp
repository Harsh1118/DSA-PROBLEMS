// Find whether path exist
// Difficulty: MediumAccuracy: 45.09%Submissions: 93K+Points: 4Average Time: 20m
// Given a grid of size n*n filled with 0, 1, 2, 3. Check whether there is a path possible from the source to destination. You can traverse up, down, right and left.
// The description of cells is as follows:

// A value of cell 1 means Source.
// A value of cell 2 means Destination.
// A value of cell 3 means Blank cell.
// A value of cell 0 means Wall (blocked cell which we cannot traverse).
// Note: There are only a single source and a single destination.

// Examples :

// Input: grid = {{3,0,3,0,0},{3,0,0,0,3},{3,3,3,3,3},{0,2,3,0,0},{3,0,0,1,3}}
// Output: 0
// Explanation: The grid is-
// 3 0 3 0 0
// 3 0 0 0 3
// 3 3 3 3 3
// 0 2 3 0 0
// 3 0 0 1 3
// There is no path to reach at (3,1) i,e at destination from (4,3) i,e source.
// Input: grid = {{1,3},{3,2}}
// Output: 1
// Explanation: The grid is-
// 1 3
// 3 2
// There is a path from (0,0) i,e source to (1,1) i,e destination.
// Expected Time Complexity: O(n2)
// Expected Auxiliary Space: O(n2)

// Constraints:
// 1 ≤ n ≤ 500

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j, int n)
    {
        return i >= 0 && j >= 0 && i < n && j < n;
    }
    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>> &grid)
    {
        // code here

        vector<int> Sourcepos;
        vector<int> Targetpos;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    Sourcepos.push_back(i);
                    Sourcepos.push_back(j);
                }

                if (grid[i][j] == 2)
                {
                    Targetpos.push_back(i);
                    Targetpos.push_back(j);
                }
            }
        }

        if (Sourcepos.empty())
        {
            return 0;
        }

        if (Targetpos.empty())
        {
            return 0;
        }

        queue<pair<int, int>> q;
        q.push({Sourcepos[0], Sourcepos[1]});

        while (!q.empty())
        {
            int count = q.size();

            while (count--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int new_i = i + row[k];
                    int new_j = j + col[k];

                    if (valid(new_i, new_j, grid.size()) && grid[new_i][new_j])
                    {
                        if (new_i == Targetpos[0] && new_j == Targetpos[1])
                        {
                            return true;
                        }
                        grid[new_i][new_j] = 0;
                        q.push({new_i, new_j});
                    }
                }
            }
        }
        return false;
    }
};