//     Question 
/*Given an array arr[] with non-negative integers representing the height of blocks. If the width of each block is 1, 
compute how much water can be trapped between the blocks during the rainy season. 

Examples:

Input: arr[] = [3, 0, 1, 0, 4, 0 2]
Output: 10
Explanation: Total water trapped = 0 + 3 + 2 + 3 + 0 + 2 + 0 = 10 units.

Input: arr[] = [3, 0, 2, 0, 4]
Output: 7
Explanation: Total water trapped = 0 + 3 + 1 + 3 + 0 = 7 units.
Input: arr[] = [1, 2, 3, 4]
Output: 0
Explanation: We cannot trap water as there is no height bound on both sides.
Input: arr[] = [2, 1, 5, 3, 1, 0, 4]
Output: 9
Explanation: Total water trapped = 0 + 1 + 0 + 1 + 3 + 4 + 0 = 9 units.
*/

// solution is :- 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        int max_index=0;
    for(int i = 1; i<arr.size();i++) {
        if(arr[i]>arr[max_index]) {
            max_index=i;
        }
    }
    vector<int>water(n);
    water[0]=0;
    water[n-1]=0;
    int left=0,right=n-1,left_height=arr[0],right_height=arr[n-1],sum=0;
    for(left = 1;left<max_index;left++) {
        int diff=left_height-arr[left];
        if(diff>0) {
            water[left]=diff;
        }
        else if(diff<=0) {
            water[left]=0;
            left_height=arr[left];
        }
    }
    for(right = n-2;right>max_index;right--) {
        int diff = right_height-arr[right];
        if(diff>0) {
            water[right]=diff;
        }
        else if(diff<=0) {
            water[right]=0;
            right_height=arr[right];
        }
    }
    for(int i =0;i<n;i++) {
        sum+=water[i];
    }
    return sum;
    }
};