// Given a square chessboard, the initial position of Knight and position of a target. Find out the minimum steps a Knight will take to reach the target position.If it cannot reach the target position return -1.

// Note:
// The initial and the target position co-ordinates of Knight have been given accoring to 1-base indexing.

// Example 1:

// Input:
// N=6
// knightPos[ ] = {4, 5}
// targetPos[ ] = {1, 1}
// Output:
// 3
// Explanation:

// Knight takes 3 step to reach from
// (4, 5) to (1, 1):
// (4, 5) -> (5, 3) -> (3, 2) -> (1, 1).

// Example 2:

// Input:
// N=8
// knightPos[ ] = {7, 7}
// targetPos[ ] = {1, 5}
// Output:
// 4
// Explanation:
// Knight takes 4 steps to reach from
// (7, 7) to (1, 5):
// (4, 5) -> (6, 5) -> (5, 3) -> (7, 2) -> (1, 5).

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function minStepToReachTarget() which takes the inital position of Knight (KnightPos), the target position of Knight (TargetPos) and the size of the chess board (N) as an input parameters and returns the minimum number of steps required by the knight to reach from its current position to the given target position.If it cannot reach the target position return -1.

// Expected Time Complexity: O(N2).
// Expected Auxiliary Space: O(N2).

// Constraints:
// 1 <= N <= 1000
// 1 <= Knight_pos(X, Y), Targer_pos(X, Y) <= N

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int row[8] = {2, 2, -2, -2, 1, -1, 1, -1};
    int col[8] = {1, -1, 1, -1, 2, 2, -2, -2};

    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    int minStepToReachTarget(vector<int> &Knightpos, vector<int> &Targetpos, int N)
    {
        // Code here
        Knightpos[0]--;
        Knightpos[1]--;
        Targetpos[0]--;
        Targetpos[1]--;

        if (Targetpos[0] == Knightpos[0] && Targetpos[1] == Knightpos[1])
        {
            return 0;
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> chess(N, vector<bool>(N, 0));
        q.push({Knightpos[0], Knightpos[1]});
        chess[Knightpos[0]][Knightpos[1]] = 1;
        int step = 0;

        while (!q.empty())
        {
            int count = q.size();

            while (count--)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 8; k++)
                {
                    int new_i = i + row[k];
                    int new_j = j + col[k];

                    if (valid(new_i, new_j, N, N) && !chess[new_i][new_j])
                    {
                        if (Targetpos[0] == new_i && Targetpos[1] == new_j)
                        {
                            return step + 1;
                        }

                        chess[new_i][new_j] = 1;
                        q.push({new_i, new_j});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};