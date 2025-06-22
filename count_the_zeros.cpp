/*
Given an array arr of only 0's and 1's. The array is sorted in such a manner that all the 1's are placed first 
and then they are followed by all the 0's. Find the count of all the 0's.

Examples:

Input: arr[] = [1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0]
Output: 3
Explanation: There are 3 0's in the given array.
Input: arr[] = [0, 0, 0, 0, 0]
Output: 5
Explanation: There are 5 0's in the array.
Constraints:
1 <= arr.size <= 105
0 <= arr[i] <= 1

Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
  public:
    int countZeroes(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int count = 0;
        for(int i = 0; i<arr.size(); i++)
        {
            if(arr[i]==0)
            {
                count++;
            }
        }
        return count;
    }
};