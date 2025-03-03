/*Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array(In Place). 
In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....
If there are multiple solutions, find the lexicographically smallest one.

Note: The given array is sorted in ascending order, and you don't need to return anything to change the original array.

Examples:

Input: arr[] = [1, 2, 3, 4, 5]
Output: [2, 1, 4, 3, 5]
Explanation: Array elements after sorting it in the waveform are 2, 1, 4, 3, 5.
Input: arr[] = [2, 4, 7, 8, 9, 10]
Output: [4, 2, 8, 7, 10, 9]
Explanation: Array elements after sorting it in the waveform are 4, 2, 8, 7, 10, 9.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
      // arr: input array
      // Function to sort the array into a wave-like array.
      void convertToWave(vector<int>& arr) {
          // code here
          int first = 0 , second = 1;
          while(second<arr.size())
          {
              swap(arr[first],arr[second]);
              first+=2;
              second+=2;
          }
          
      }
  };