/*
Given an array, arr[]. Sort the array using bubble sort algorithm.

Examples :

Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Input: arr[] = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
Output: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
Input: arr[] = [1, 2, 3, 4, 5]
Output: [1, 2, 3, 4, 5]
Explanation: An array that is already sorted should remain unchanged after applying bubble sort.
Constraints:
1 <= arr.size() <= 103
1 <= arr[i] <= 103
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
      // Function to sort the array using bubble sort algorithm.
      void bubbleSort(vector<int>& arr) {
          // Your code here
          for(int i = 0; i<arr.size()-1; i++)
          {
              for(int j = i+1; j<arr.size(); j++)
              {
                  if(arr[i]>arr[j])
                  {
                      swap(arr[i],arr[j]);
                  }
              }
          }
      }
  };