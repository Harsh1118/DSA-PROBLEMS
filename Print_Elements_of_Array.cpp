/*
Given an array arr[], print all its elements space-separated.

Note: You don't need to move to the next line after printing all elements of the array (space-separated)

Examples:

Input: arr[] = [1, 2, 3, 4, 5]
Output: 1 2 3 4 5
Input: arr[] = [2, 3, 5, 5]
Output: 2 3 5 5
Constraints:
1 <= arr.size <= 106
1 <= arr[i] <= 108

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    // Just print the space seperated array elements
    void printArray(vector<int> &arr) {
        // code here
        for(int i = 0; i<arr.size(); i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};