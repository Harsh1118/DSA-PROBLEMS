// Given an array arr[] of integers, determine whether it contains a triplet whose sum equals zero.
 //Return true if such a triplet exists, otherwise, return false.

// Examples:

// Input: arr[] = [0, -1, 2, -3, 1]
// Output: true
// Explanation: The triplet [0, -1, 1] has a sum equal to zero.
// Input: arr[] = [1, 2, 3]
// Output: false
// Explanation: No triplet with a sum of zero exists.
// Input: arr[] = [-5, 3, 2, -1, 0, 1]
// Output: true
// Explanation: The triplet [-5, 3, 2] has a sum equal to zero.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    // Function to find triplets with zero sum.
    bool findTriplets(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int x = 0;
        for(int i = 0;i<n-2;i++) {
            int x = 0-arr[i];
            int start = i+1,end=n-1;
            while(start<end) {
                if(arr[start]+arr[end]==x) {
                    return true;
                }
                if(arr[start]+arr[end]<x) {
                    start++;
                }
                else {
                    end--;
                }
            }
        }
        return false;
    }
};