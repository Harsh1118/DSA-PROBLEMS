/*
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of 
all the elements in the subarray is strictly less than k.

 

Example 1:

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
Example 2:

Input: nums = [1,2,3], k = 0
Output: 0
 

Constraints:

1 <= nums.length <= 3 * 104
1 <= nums[i] <= 1000
0 <= k <= 106

*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0  , end = 0 , n = nums.size() , product = 1;
        int count = 0;
        while(end<n)
        {
            product *= nums[end];
            while(product>=k && start<=end)
            {
                product/=nums[start];
                start++;
            }
            count += 1+end-start;
            end++;
        }
        return count;
    }
};