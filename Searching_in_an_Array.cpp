/*
Given an integer k and array arr. Your task is to return the position of the first occurrence of k in the given array and if
 element k is not present in the array then return -1.

Note: 1-based indexing is followed here.

Examples:

Input: k = 16 , arr = [9, 7, 16, 16, 4]
Output: 3
Explanation: The value 16 is found in the given array at positions 3 and 4, with position 3 being the first occurrence.
Input: k=98 , arr = [1, 22, 57, 47, 34, 18, 66]
Output: -1
Explanation: k = 98 isn't found in the given array.
Constraints:
1 <= arr.size <= 106
1 <= arr[i] <= 109
1 <= k <= 106

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
    int search(int k, vector<int>& arr) {
        // code here
        for(int i = 0; i<arr.size(); i++)
        {
            if(arr[i]==k)
            {
                return i+1;
            }
        }
        return -1;
    }
};
