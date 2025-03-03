/*Given a square matrix mat[][] of size n x n. 
The task is to rotate it by 90 degrees in an anti-clockwise direction without using any extra space. 

Examples:

Input: mat[][] = [[1, 2, 3],
                [4, 5, 6]
                [7, 8, 9]]
Output: Rotated Matrix:
[3, 6, 9]
[2, 5, 8]
[1, 4, 7]
Input: mat[][] = [[1, 2],
                [3, 4]]
Output: Rotated Matrix:
[2, 4]
[1, 3]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
      // Function to rotate matrix anticlockwise by 90 degrees.
      void rotateby90(vector<vector<int>>& mat) {
          // code here
          
          for(int i = 0; i<mat.size()-1; i++)
          {
              for(int j = i+1; j<mat[0].size(); j++)
              {
                  swap(mat[i][j],mat[j][i]);
              }
          }
          
          for(int i = 0; i<mat[0].size(); i++)
          {
              int start = 0, end = mat.size()-1;
              while(start<end)
              {
                  swap(mat[start][i],mat[end][i]);
                  start++,end--;
              }        
              
          }
      }
  };
  
