/*
You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one 
number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>p;
        int minimum , maximum = INT_MIN;

        for(int i = 0; i<nums.size(); i++)
        {
            p.push(make_pair(nums[i][0],make_pair(i,0)));
            maximum = max(maximum,nums[i][0]);
        }
        minimum = p.top().first;
        vector<int>ans(2);
        ans[0]=minimum;
        ans[1]=maximum;
        pair<int,pair<int,int>>temp;
        int row , col , elem;

        while(p.size()==nums.size())
        {
            temp = p.top();
            p.pop();

            elem = temp.first;
            row = temp.second.first;
            col = temp.second.second;

            if(col+1<nums[row].size())
            {
                col++;
                p.push(make_pair(nums[row][col],make_pair(row,col)));
                maximum = max(maximum,nums[row][col]);
                minimum = p.top().first;

                if(maximum-minimum < ans[1]-ans[0])
                {
                    ans[0] = minimum;
                    ans[1] = maximum;
                }
            }
        }
        return ans;
    }
};