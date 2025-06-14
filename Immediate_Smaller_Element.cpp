/*
Given an integer array arr. For each element in the array, check whether the right adjacent element (on the next immediate position) of the
 array is smaller. If the next element is smaller, update the current index to that element. If not, then update to -1.

Note: Update the array in itself.

Examples:

Input: arr[] = [4, 2, 1, 5, 3]
Output: [2, 1, -1, 3, -1]
Explanation: Array elements are 4, 2, 1, 5, 3. Next to 4 is 2 which is smaller, so we print 2. Next of 2 is 1 which is smaller,so we print 1. 
Next of 1 is 5 which is greater, so we print -1. Next of 5 is 3 which is smaller, so we print 3.  Note that for last element, output is always  
going to be -1 because there is no element on right.
Input: arr[] = [5, 6, 2, 3, 1, 7]
Output: [-1, 2, -1, 1, -1, -1]
Explanation: Next to 5 is 6 which is greater, so we print -1. Next of 6 is 2 which is smaller, so we print 2. Next of 2 is 3 which is greater, 
so we print -1. Next of 3 is 1 which is smaller, so we print 1. Next of 1 is 7 which is greater, so we print -1. Note that for last element,
 output is always going to be -1 because there is no element on right.
Input: arr[] = [4, 1]
Output: [1, -1]
Explanation: 4 will be updated to 1 and 1 will be updated to -1.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(1)
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
  public:
    void immediateSmaller(vector<int>& arr) {
        //  code here
        for(int i = 0; i<arr.size()-1; i++)
        {
            if(arr[i]>arr[i+1])
            {
                arr[i]=arr[i+1];
            }
            else
            {
                arr[i]=-1;
            }
        }
         arr[arr.size()-1]=-1;
    }
};