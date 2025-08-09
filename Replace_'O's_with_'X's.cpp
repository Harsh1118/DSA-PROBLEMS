/*
Given a matrix mat where every element is either 'O' or 'X'. Replace all 'O' or a group of 'O' with 'X' that are
surrounded by 'X'.

A 'O' (or a set of 'O') is considered to be surrounded by 'X' if there are 'X' at locations just below,
just above, just left and just right of it.

Examples:

Input: mat =
[['X', 'X', 'X', 'X'],
['X', 'O', 'X', 'X'],
['X', 'O', 'O', 'X'],
['X', 'O', 'X', 'X'],
['X', 'X', 'O', 'O']]
Output:
[['X', 'X', 'X', 'X'],
['X', 'X', 'X', 'X'],
['X', 'X', 'X', 'X'],
['X', 'X', 'X', 'X'],
['X', 'X', 'O', 'O']]
Explanation: We only changed those 'O' that are surrounded by 'X'
Input: mat =
[['X', 'O', 'X', 'X'],
['X', 'O', 'X', 'X'],
['X', 'O', 'O', 'X'],
['X', 'O', 'X', 'X'],
['X', 'X', 'O', 'O']]
Output:
[['X', 'O', 'X', 'X'],
['X', 'O', 'X', 'X'],
['X', 'O', 'O', 'X'],
['X', 'O', 'X', 'X'],
['X', 'X', 'O', 'O']]
Explanation: There's no 'O' that's surround by 'X'.
Input: mat =
[['X', 'X', 'X'],
['X', 'O', 'X'],
['X', 'X', 'X']]
Output:
[['X', 'X', 'X'],
['X', 'X', 'X'],
['X', 'X', 'X']]
Explanation: There's only one 'O' that's surround by 'X'.
Constraints:
1 ≤ mat.size() ≤ 100
1 ≤ mat[0].size() ≤ 100

Expected Complexities
Time Complexity: O(n * m)
Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int r;
    int c;

    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    vector<vector<char>> fill(vector<vector<char>> &mat)
    {
        // code here
        r = mat.size();
        c = mat[0].size();

        queue<pair<int, int>> q;

        // check all the borders that 0 is present or not

        for (int j = 0; j < c; j++)
        {
            if (mat[0][j] == 'O')
            {
                q.push(make_pair(0, j));
                mat[0][j] = 'T';
            }
        }

        for (int i = 1; i < r; i++)
        {
            if (mat[i][0] == 'O')
            {
                q.push(make_pair(i, 0));
                mat[i][0] = 'T';
            }
        }

        for (int j = 1; j < c; j++)
        {
            if (mat[r - 1][j] == 'O')
            {
                q.push(make_pair(r - 1, j));
                mat[r - 1][j] = 'T';
            }
        }

        for (int i = 1; i < r - 1; i++)
        {
            if (mat[i][c - 1] == 'O')
            {
                q.push(make_pair(i, c - 1));
                mat[i][c - 1] = 'T';
            }
        }

        while (!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                if (valid(i + row[k], j + col[k]) && mat[i + row[k]][j + col[k]] == 'O')
                {
                    mat[i + row[k]][j + col[k]] = 'T';
                    q.push(make_pair(i + row[k], j + col[k]));
                }
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 'O')
                {
                    mat[i][j] = 'X';
                }

                else if (mat[i][j] == 'T')
                {
                    mat[i][j] = 'O';
                }
            }
        }
        return mat;
    }
};