/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    void permutation(vector<int>&nums,vector<vector<int>>&ans,int index)
    {
        if(index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
    
        for(int i = index; i<nums.size(); i++)
        {
            swap(nums[index],nums[i]);
            permutation(nums,ans,index+1);
            swap(nums[index],nums[i]);
        }
    }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>>ans;
            permutation(nums,ans,0);
            return ans;
            
        }
    };