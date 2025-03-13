/*
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    
        void subsequence(vector<int>&nums , int index , int n , vector<vector<int>>&ans,vector<int>&temp)
        {
            if(index==n)
            {
                ans.push_back(temp);
                return;
            }
    
            subsequence(nums,index+1,nums.size(),ans,temp);
    
            temp.push_back(nums[index]);
            subsequence(nums,index+1,nums.size(),ans,temp);
            temp.pop_back();
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>>ans;
            vector<int>temp;
            subsequence(nums,0,nums.size(),ans,temp);
            return ans;
    
        }
    };