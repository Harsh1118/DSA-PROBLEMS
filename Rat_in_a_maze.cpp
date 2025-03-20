/*
Consider a rat placed at position (0, 0) in an n x n square matrix mat. The rat's goal is to reach the destination at position (n-1, n-1). 
The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Note: In a path, no cell can be visited more than one time. If the source cell is 0, 
the rat cannot move to any other cell. In case of no path, return an empty list.+

The task is to find all possible paths the rat can take to reach the destination, 
starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit a
ny cell along the same path. Furthermore, the rat can only move to adjacent cells that are within 
the bounds of the matrix and not blocked.

Return the final result vector in lexicographically smallest order.

Examples:

Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, 
when printed in sorted order we get DDRDRR DRDDRR.
Input: mat[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists and the destination cell is blocked.
Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", 
These are returned in lexicographically sorted order.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};
    string direction = "UDLR";
    
    bool valid(int i , int j , int n)
    {
        return i>=0 && j>= 0 && i<n && j <n;
    }
    
    void total(vector<vector<int>>&matrix , int i , int j , int n , string &path, vector<string>&ans,vector<vector<bool>>&visited)
    {
        if(i==n-1 && j == n-1)
        {
            ans.push_back(path);
            return ;
        }
        
        visited[i][j]=1;
        for(int k = 0; k<4; k++)
        {
            if(valid(i+row[k],j+col[k],n) && matrix[i+row[k]][j+col[k]] && !visited[i+row[k]][j+col[k]])
            {
                path.push_back(direction[k]);
                total(matrix,i+row[k],j+col[k],n,path,ans,visited);
                path.pop_back();
            }
        }
        visited[i][j]=0;
    }
    
      vector<string> findPath(vector<vector<int>> &mat) {
          // code here
          int n = mat.size();
          
          vector<vector<bool>>visited(n,vector<bool>(n,0));
          vector<string>ans;
          string path;
          
          if(mat[0][0]==0 || mat[n-1][n-1]==0)
          {
              return ans;
          }
          
          total(mat , 0 , 0 , n , path, ans , visited );
      }
  };