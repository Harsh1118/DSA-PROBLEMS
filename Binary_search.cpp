/*Given a sorted array arr and an integer k, find the position(0-based indexing) at which k is present in the array 
using binary search.

Note: If multiple occurrences are there, please return the smallest index.

Examples:

Input: arr[] = [1, 2, 3, 4, 5], k = 4
Output: 3
Explanation: 4 appears at index 3.
Input: arr[] = [11, 22, 33, 44, 55], k = 445
Output: -1
Explanation: 445 is not present.
Input: arr[] = [1, 1, 1, 1, 2], k = 1
Output: 0
Explanation: 1 appears at index 0.

Note: Try to solve this problem in constant space i.e O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
      int binarysearch(vector<int> &arr, int k) {
          // code here
          int index = -1;
          int start = 0 , end = arr.size()-1;
          
          while(start<=end)
          {
              int mid = start+(end-start)/2;
              if(arr[mid]==k)
              {
                  index = mid;
                  end=mid-1;
              }
              else if(arr[mid]<k) 
              {
                  start=mid+1;
              }
              else 
              {
                  end = mid-1;
              }
          }
          return index;
      }
  };