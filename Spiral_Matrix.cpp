/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int row = matrix.size();
            int col = matrix[0].size();
            vector<int>ans;
    
            int top = 0;
            int right = col-1;
            int bottom = row-1;
            int left = 0;
    
            while(left<=right&&top<=bottom)
            {
                for(int i = left; i<=right; i++)
                {
                    ans.push_back(matrix[top][i]);
                }
                top++;
                for(int j = top; j<=bottom; j++)
                {
                    ans.push_back(matrix[j][right]);
                }
                right--;
                if(top<=bottom)
                {
                for(int k = right; k>=left; k--)
                {
                    ans.push_back(matrix[bottom][k]);
                }
                 bottom--;
                }
    
                if(left<=right)
                {
                for(int p = bottom; p>=top; p--)
                {
                    ans.push_back(matrix[p][left]);
                }
                 left++;
                }
               
            }
            return ans;
        }
    };