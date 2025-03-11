// Given an array of integers nums, sort the array in ascending order and return it.

// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the 
// smallest space complexity possible.

 

// Example 1:

// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), 
// while the positions of other numbers are changed (for example, 1 and 5).
// Example 2:

// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessairly unique.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    
    void merge(vector<int>&arr,int start,int mid,int end)
    {
        vector<int>temp(end-start+1);
        int left = start , right = mid+1,index = 0;
        while(left<=mid && right <= end)
        {
            if(arr[left]<=arr[right])
            {
                temp[index] = arr[left];
                index++,left++;
            }
    
            else
            {
                temp[index] = arr[right];
                index++,right++;
            }
        }
    
        while(left<=mid)
        {
            temp[index] = arr[left];
            left++,index++;
        }
    
        while(right<=end)
        {
            temp[index] = arr[right];
            index++,right++;
        }
    
        index = 0;
        while(start<=end)
        {
            arr[start] = temp[index];
            start++,index++;
        }
    }
    
    void merge_sort(vector<int>&arr,int start,int end)
    {
        if(start == end)
        {
            return;
        }
        int mid = start+(end-start)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
        vector<int> sortArray(vector<int>& nums) {
            merge_sort(nums,0,nums.size()-1);
            return nums;
        }
    };