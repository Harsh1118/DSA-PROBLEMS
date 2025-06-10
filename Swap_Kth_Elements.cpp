/*
Given an array arr[], swap the kth element from the beginning with the kth element from the end.

Note: 1-based indexing is followed.

Examples :

Input: arr[] = [1, 2, 3, 4, 5, 6, 7, 8], k = 3
Output: [1, 2, 6, 4, 5, 3, 7, 8]
Explanation: 3rd element from beginning is 3 and 3rd element from end is 6, so we replace 3 & 6.
Input: arr[] = [5, 3, 6, 1, 2], k = 2
Output: [5, 1, 6, 3, 2]
Explanation: 2nd element from beginning is 3 and from end is 1.
Constraints:
1 ≤ arr.size(), k ≤ 106
-109 ≤ arr[i] ≤ 109

Expected Complexities
Time Complexity: O(1)
Auxiliary Space: O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    void swapKth(vector<int> &arr, int k) {
        // code here
        int start = k-1;
        int end = arr.size()-k;
        swap(arr[start],arr[end]);
    }
};