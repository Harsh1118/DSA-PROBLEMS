/*
Given a matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. 
Find the kth smallest element in the matrix.

Examples:
Input: n = 4, mat[][] = [[16, 28, 60, 64], [22, 41, 63, 91], [27, 50, 87, 93], [36, 78, 87, 94]], k = 3
Output: 27
Explanation: 27 is the 3rd smallest element.
Input: n = 4, mat[][] = [[10, 20, 30, 40], [15, 25, 35, 45], [24, 29, 37, 48], [32, 33, 39, 50]], k = 7
Output: 30
Explanation: 30 is the 7th smallest element.
Constraints:
1 <= n <= 500
1 <= mat[i][j] <= 10000
1 <= k <= n*n

Expected Complexities
Time Complexity: O(n * log (mat[i][j] ))
Auxiliary Space: O(1)

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
        vector<pair<int,pair<int,int>>>temp;
        for(int i = 0; i<matrix[0].size(); i++)
        {
            temp.push_back(make_pair(matrix[i][0],make_pair(i,0)));           
        }
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>p(temp.begin(),temp.end());     
        
        int ans;
        pair<int,pair<int,int>>element; 
        int i , j;
        while(k--)
        {
            element = p.top();
            p.pop();
            ans = element.first;
            i = element.second.first;
            j = element.second.second;
            if(j+1<matrix.size())
            {
                p.push(make_pair(matrix[i][j+1],make_pair(i,j+1)));
            }
        }
        return ans;
    }
};