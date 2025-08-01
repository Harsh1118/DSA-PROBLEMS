/*
You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

 

Example 1:

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], 
[3,2,3,3], [2,3,3] and [3,3].
Example 2:

Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxele = 0 , n = nums.size();
        for(int i = 0; i<n; i++)
        {
            maxele = max(maxele,nums[i]);
        }

        long long total = 0;
        int count = 0 , start = 0 ,end = 0;

        while(end<n)
        {
            if(nums[end]==maxele)
            {
                count++;
            }

            while(count==k)
            {
                total += n-end;
                if(nums[start]==maxele)
                {
                    count--;
                }
                start++;
            }
            end++;
        }

        return total;
    }
};