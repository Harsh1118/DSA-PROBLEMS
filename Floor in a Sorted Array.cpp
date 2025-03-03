/*Given a sorted array arr[] (with unique elements) and an integer k, 
find the index (0-based) of the largest element in arr[] that is less than or equal to k. 
This element is called the "floor" of k. If such an element does not exist, return -1.

Examples

Input: arr[] = [1, 2, 8, 10, 11, 12, 19], k = 0
Output: -1
Explanation: No element less than 0 is found. So output is -1.
Input: arr[] = [1, 2, 8, 10, 11, 12, 19], k = 5
Output: 1
Explanation: Largest Number less than 5 is 2 , whose index is 1.
Input: arr[] = [1, 2, 8], k = 1
Output: 0
Explanation: Largest Number less than or equal to  1 is 1 , whose index is 0.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
  
      int findFloor(vector<int>& arr, int k) {
  
          // Your code here
          sort(arr.begin(),arr.end());
          int index = 0;
          while(index<arr.size())
          {
              if(arr[index]>k)
              {
                  return index-1;
              }
              else if(arr[index]==k)
              {
                  return index;
              }
              else 
              {
                  index++;
              }
          }
      }
  };