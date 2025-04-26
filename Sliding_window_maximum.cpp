/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very 
left of the array to the very right. You can only see the k numbers in the window. Each time the sliding 
window moves right by one position.

Return the max sliding window.

 

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Example 2:

Input: nums = [1], k = 1
Output: [1]
 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
1 <= k <= nums.length
*/
#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            deque<int>d;
            vector<int>ans;
            for(int i = 0; i<k-1; i++)
            {
                if(d.empty())
                {
                    d.push_back(i);
                }
                else
                {
                    while(!d.empty()&&nums[i]>nums[d.back()])
                    {
                        d.pop_back();
                    }
    
                    d.push_back(i);
                }
            }
    
            for(int i = k-1; i<nums.size(); i++)
            {
                while(!d.empty()&&nums[i]>nums[d.back()])
                {
                    d.pop_back();
                }
                d.push_back(i);
    
                if(d.front()<=i-k)
                {
                    d.pop_front();
                }
    
                ans.push_back(nums[d.front()]);
            }
    
            return ans;
        }
    };