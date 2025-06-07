/*
Given an array arr[] of integers, calculate the median.

Examples:

Input: arr[] = [90, 100, 78, 89, 67]
Output: 89
Explanation: After sorting the array middle element is the median 
Input: arr[] = [56, 67, 30, 79]
Output: 61.5
Explanation: In case of even number of elements, average of two middle elements is the median. 
Input: arr[] = [1, 2]
Output: 1.5
Explanation: The average of both elements will result in 1.5.
Constraints:
1 <= arr.size() <= 105
1 <= arr[i] <= 105

Expected Complexities
Time Complexity: O(n log n)
Auxiliary Space: O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    double findMedian(vector<int> &arr) {
        // code here.
        int  n = arr.size();
        sort(arr.begin(),arr.end());
        if(n%2==0)
        {
            int i = n/2;
            int j = i-1;
            double sum = arr[i]+arr[j];
            sum/=2;
            return sum;
        }
        else
        {
            int i = n/2;
            double sum = arr[i];
            return sum;
        }
    }
};