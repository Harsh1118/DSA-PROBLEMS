// Given k sorted arrays arranged in the form of a matrix of size k * k. The task is to merge them into one sorted array. 
// Return the merged sorted array ( as a pointer to the merged sorted arrays in cpp, as an ArrayList in java, 
   // and list in python).


// Examples :

// Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
// Output: 1 2 3 4 5 6 7 8 9
// Explanation: Above test case has 3 sorted arrays of size 3, 3, 3 arr[][] = [[1, 2, 3],[4, 5, 6],[7, 8, 9]]. 
// The merged list will be [1, 2, 3, 4, 5, 6, 7, 8, 9].
// // Input: k = 4, arr[][]={{1,2,3,4},{2,2,3,4},{5,5,6,6},{7,8,9,9}}
// // Output: 1 2 2 2 3 3 4 4 5 5 6 6 7 8 9 9 
// // Explanation: Above test case has 4 sorted arrays of size 4, 4, 4, 4 arr[][] = [[1, 2, 2, 2], [3, 3, 4, 4], 
// [5, 5, 6, 6], [7, 8, 9, 9 ]]. The merged list will be [1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 8, 9, 9].
// Expected Time Complexity: O(k2*Log(k))
// Expected Auxiliary Space: O(k2)

// Constraints:
// 1 <= k <= 100
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    // Function to merge k sorted arrays.
    
    void merge(vector<int>&arr,int start,int mid,int end)
{
    vector<int>temp(end-start+1);
    int left = start , right = mid+1,index = 0;
    while(left<=mid && right <= end)
    {
        if(arr[left]<=arr[right])
        {
            temp[index] = arr[left];
            index++,left++;
        }

        else
        {
            temp[index] = arr[right];
            index++,right++;
        }
    }

    while(left<=mid)
    {
        temp[index] = arr[left];
        left++,index++;
    }

    while(right<=end)
    {
        temp[index] = arr[right];
        index++,right++;
    }

    index = 0;
    while(start<=end)
    {
        arr[start] = temp[index];
        start++,index++;
    }
}

void merge_sort(vector<int>&arr,int start,int end,int portion,int k)
{
    if(portion<2)
    {
        return;
    }
    if(start == end)
    {
        return;
    }
    int mid = start+(portion/2)*k-1;
    merge_sort(arr,start,mid,portion/2,k);
    merge_sort(arr,mid+1,end,portion-portion/2,k);
    merge(arr,start,mid,end);
}
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
        // code here
        vector<int>ans;
        for(int i = 0; i<arr.size(); i++)
        {
            for(int j = 0; j<arr.size(); j++)
            {
                ans.push_back(arr[i][j]);
            }
        }
        
        merge_sort(ans,0,ans.size()-1,K,K);
        return ans;
    }
};
