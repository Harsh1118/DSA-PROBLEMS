/*
Given a sorted array arr and a value target, return an array of size 2. The first value is the number of
 elements less than or equal to the target, and the second value is the number of elements greater than or 
 equal to the target.

Examples:

Input: arr[] = [1, 2, 8, 10, 11, 12, 19],  target = 0
Output: 0, 7
Explanation: There are no elements less or equal to 0 and 7 elements greater to 0.
Input: arr[] = [1, 5, 8, 12, 12, 12, 19], target = 12
Output: 6, 4
Explanation: There are 6 elements less or equal to 12 and 4 elements greater or equal to 12.

Time Complexity: O(log n)   Auxiliary Space: O(1)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    int getless(vector<int>&arr,int target)
    {
        int start = 0, end = arr.size()-1, index = -1;
        while(start<=end)
        {
            int mid = start + (end-start)/2;
            if(arr[mid]<=target)
            {
                index=mid;
                start=mid+1;
            }
            
            else
            {
                end = mid-1;
            }
        }
        return index+1;
    }
    
    int getmore(vector<int>&arr , int target)
    {
        int start = 0, end = arr.size()-1, index = -1;
        
        while(start<=end)
        {
            int mid = start +(end-start)/2;
            
            if(arr[mid]>=target)
            {
                index = mid;
                end = mid-1;
            }
            
            else
            {
                start = mid+1;
            }
        }
        if(index==-1)
        {
        return 0;
        }
        
        return arr.size()-index;
    }
      vector<int> getMoreAndLess(vector<int> &arr, int target) {
          // code here
          int small = getless(arr,target);
          int big = getmore(arr,target);
          
          return {small,big};
      }
  };
