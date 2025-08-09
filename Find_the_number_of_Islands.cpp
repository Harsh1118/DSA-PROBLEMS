/*
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of
'W's (Water) and 'L's (Land). Find the number of islands.

Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent
lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:

Input: grid[][] = [['L', 'L', 'W', 'W', 'W'], ['W', 'L', 'W', 'W', 'L'], ['L', 'W', 'W', 'L', 'L'],
['W', 'W', 'W', 'W', 'W'], ['L', 'W', 'L', 'L', 'W']]
Output: 4
Explanation:
The image below shows all the 4 islands in the grid.

Input: grid[][] = [['W', 'L', 'L', 'L', 'W', 'W', 'W'], ['W', 'W', 'L', 'L', 'W', 'L', 'W']]
Output: 2
Expanation:
The image below shows 2 islands in the grid.

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] = {'L', 'W'}


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
    int row[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    bool valid(int i, int j)
    {
        return i >= 0 && i < r && j >= 0 && j < c;
    }
    int countIslands(vector<vector<char>> &grid)
    {
        // Code here
        r = grid.size();
        c = grid[0].size();

        queue<pair<int, int>> q;
        int count = 0;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 'L')
                {
                    count++;

                    q.push(make_pair(i, j));
                    grid[i][j] = 'W';

                    while (!q.empty())
                    {
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();

                        for (int k = 0; k < 8; k++)
                        {
                            if (valid(new_i + row[k], new_j + col[k]) && grid[new_i + row[k]][new_j + col[k]] == 'L')
                            {
                                grid[new_i + row[k]][new_j + col[k]] = 'W';
                                q.push(make_pair(new_i + row[k], new_j + col[k]));
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};