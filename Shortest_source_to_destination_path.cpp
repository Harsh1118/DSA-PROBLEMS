// Given a 2D binary matrix A(0-based index) of dimensions NxM. Find the minimum number of steps required to reach from (0,0) to (X, Y).
// Note: You can only move left, right, up and down, and only through cells that contain 1.

// Example 1:

// Input:
// N=3, M=4
// A=[[1,0,0,0],
//    [1,1,0,1],
//    [0,1,1,1]]
// X=2, Y=3
// Output:
// 5
// Explanation:
// The shortest path is as follows:
// (0,0)->(1,0)->(1,1)->(2,1)->(2,2)->(2,3).
// Example 2:

// Input:
// N=3, M=4
// A=[[1,1,1,1],
//    [0,0,0,1],
//    [0,0,0,1]]
// X=0, Y=3
// Output:
// 3
// Explanation:
// The shortest path is as follows:
// (0,0)->(0,1)->(0,2)->(0,3).
// Your Task:
// You don't need to read input or print anything. Your task is to complete the function shortestDistance() which takes the integer N, M, X, Y, and the 2D binary matrix A as input parameters and returns the minimum number of steps required to go from (0,0) to (X, Y).If it is impossible to go from (0,0) to (X, Y),then function returns -1. If value of the cell (0,0) is 0 (i.e  A[0][0]=0) then return -1.

// Constraints:
// 1 <= N,M <= 250
// 0 <= X < N
// 0 <= Y < M
// 0 <= A[i][j] <= 1

// Expected Complexities
// Time Complexity: O(n * m)
// Auxiliary Space: O(n * m)

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

    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        // code here

        if (X == 0 && Y == 0)
        {
            return 0;
        }

        if (!A[0][0])
        {
            return -1;
        }
        queue<pair<int, int>> q;
        q.push({0, 0});
        int step = 0;

        A[0][0] = 0;

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

                    if (valid(new_i, new_j, N, M) && A[new_i][new_j])
                    {
                        if (new_i == X && new_j == Y)
                        {
                            return step + 1;
                        }

                        A[new_i][new_j] = 0;
                        q.push({new_i, new_j});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};