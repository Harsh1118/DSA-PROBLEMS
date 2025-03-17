/*
Given a array arr of integers, return the sums of all subsets in the list.  Return the sums in any order.

Examples:

Input: arr[] = [2, 3]
Output: [0, 2, 3, 5]
Explanation: When no elements are taken then Sum = 0. When only 2 is taken then Sum = 2. 
When only 3 is taken then Sum = 3. When elements 2 and 3 are taken then Sum = 2+3 = 5.
Input: arr[] = [1, 2, 1]
Output: [0, 1, 1, 2, 2, 3, 3, 4]
Explanation: The possible subset sums are 0 (no elements), 1 (either of the 1's), 2 (the element 2), 
and their combinations.
Input: arr[] = [5, 6, 7]
Output: [0, 5, 6, 7, 11, 12, 13, 18]
Explanation: The possible subset sums are 0 (no elements), 5, 6, 7, and their combinations.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    
    void subsets(vector<int>&arr,vector<int>&ans,int index , int n , int sum , vector<int>&subset)
    {
        if(index == n)
        {
            ans.push_back(sum);
            return;
        }
        
        subsets(arr,ans,index+1,n,sum,subset);
        subset.push_back(arr[index]);
        subsets(arr,ans,index+1,n,sum+arr[index],subset);
        subset.pop_back();
    }
      vector<int> subsetSums(vector<int>& arr) {
          // code here
          vector<int>ans;
          vector<int>subset;
          subsets(arr,ans,0,arr.size(),0,subset);
          return ans;
      }
  };