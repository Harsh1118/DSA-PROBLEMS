/*Given a square mat[][]. The task is to rotate it by 90 degrees in clockwise direction without using any extra space.

Examples:

Input: mat[][] = [[1 2 3], [4 5 6], [7 8 9]]
Output:
7 4 1 
8 5 2
9 6 3
Input: mat[][] = [1 2], [3 4]
Output:
3 1 
4 2
Input: mat[][] = [[1]]
Output:
1
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void rotate(vector<vector<int> >& mat) {
    // Your code goes here
    for(int i = 0; i<mat.size()-1; i++)
    {
        for(int j = i+1; j<mat[0].size(); j++)
        {
            swap(mat[i][j],mat[j][i]);
        }
    }
    
    for(int i = 0; i<mat.size(); i++)
    {
        int start = 0 , end = mat[0].size()-1;
        
        while(start < end)
    {
        swap(mat[i][start],mat[i][end]);
        start++,end--;
    }
        
    }
}