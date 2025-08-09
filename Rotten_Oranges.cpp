/*
Given a matrix mat[][] of dimension n * m where each cell in the matrix can have values 0, 1 or 2
which has the following meaning:
0 : Empty cell
1 : Cell have fresh oranges
2 : Cell have rotten oranges

We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at
index (i, j) can rot other fresh orange at indexes (i-1, j), (i+1, j), (i, j-1), (i, j+1) (up, down, left and
right) in a unit time.

Note: Your task is to return the minimum time to rot all the fresh oranges. If not possible returns -1.

Examples:

Input: mat[][] = [[0, 1, 2], [0, 1, 2], [2, 1, 1]]
Output: 1
Explanation: Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time.
Input: mat[][] = [[2, 2, 0, 1]]
Output: -1
Explanation: Oranges at (0,0) and (0,1) can't rot orange at (0,3).
Input: mat[][] = [[2, 2, 2], [0, 2, 0]]
Output: 0
Explanation: There is no fresh orange.
Constraints:
1 ≤ mat.size() ≤ 500
1 ≤ mat[0].size() ≤ 500
mat[i][j] = {0, 1, 2}

Expected Complexities
Time Complexity: O(n * m)
Auxiliary Space: O(n * m)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    int r;
    int c;
    bool valid(int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    int orangesRotting(vector<vector<int>> &mat)
    {
        // Code here
        r = mat.size();
        c = mat[0].size();

        int good_orange = 0;

        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 2)
                {
                    q.push(make_pair(i, j));
                }
                if (mat[i][j] == 1)
                {
                    good_orange++;
                }
            }
        }

        if (!good_orange)
        {
            return 0;
        }

        int timer = 0;

        while (!q.empty())
        {
            timer++;
            int curr_orange = q.size();
            while (curr_orange--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    if (valid(i + row[k], j + col[k]) && mat[i + row[k]][j + col[k]] == 1)
                    {
                        mat[i + row[k]][j + col[k]] = 2;
                        q.push(make_pair(i + row[k], j + col[k]));
                    }
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 1)
                {
                    return -1;
                }
            }
        }

        return timer - 1;
    }
};