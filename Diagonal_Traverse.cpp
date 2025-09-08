// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

// Example 1:

// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]
// Example 2:

// Input: mat = [[1,2],[3,4]]
// Output: [1,2,3,4]

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// -105 <= mat[i][j] <= 105

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool valid(int i, int j, int n, int m)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {

        int n = mat.size();
        int m = mat[0].size();

        vector<int> ans;

        int total = n * m;

        int i = 0, j = 0;

        while (ans.size() < total)
        {
            while (valid(i, j, n, m))
            {
                ans.push_back(mat[i][j]);
                i--;
                j++;
            }

            // ye case longest diagonal ke liye hoga jab hum boundary cross kar chuke honge
            // for ex in 5x5 mat we are in (0,4) -> (-1,5) so abb hume vahe se (1,4) pe aana hai
            // na ki (0,4) pe isliye humne yaha pe row mai +2 kiya
            // given testcase mai ye apply hoga 7->5->3 wale par

            if (j == m)
            {
                i += 2;
                j--;
            }
            else
            {
                i++;
            }

            while (ans.size() < total && valid(i, j, n, m))
            {
                ans.push_back(mat[i][j]);
                i++;
                j--;
            }

            // jab hum 6->8 aa rahe the uske baad hum boundary se bahr hogaye
            //  (3,0) jo ki out of domain hai
            //  toh hum yaha col mai +2 karenge taki hum (2,2) pe pahuche na ki vapis
            //  (2,1) pe aa jaye

            if (i == n)
            {
                j += 2;
                i--;
            }
            else
            {
                j++;
            }
        }
        return ans;
    }
};