/*
You are given an array arr[] of integers. Find the total count of subarrays with their sum equal to 0.

Examples:

Input: arr[] = [0, 0, 5, 5, 0, 0]
Output: 6
Explanation: The 6 subarrays are [0], [0], [0], [0], [0,0], and [0,0].
Input: arr[] = [6, -1, -3, 4, -2, 2, 4, 6, -12, -7]
Output: 4
Explanation: The 4 subarrays are [-1, -3, 4], [-2, 2], [2, 4, 6, -12], 
and [-1, -3, 4, -2, 2]
Input: arr[] = [0]
Output: 1
Explanation: The only subarray is [0].
Constraints:    
1 <= n <= 106
-109 <= arr[ i ] <= 109

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        // code here.
        int total = 0;
        unordered_map<int,int>m;
        int prefixsum = 0;
        
        m[0]=1;
        
        for(int i = 0; i<arr.size(); i++)
        {
            prefixsum += arr[i];
            
            if(m.count(prefixsum))
            {
                total+=m[prefixsum];
                m[prefixsum]++;
            }
            
            else
            {
                m[prefixsum] = 1;
            }
        }
        return total;
    }
};