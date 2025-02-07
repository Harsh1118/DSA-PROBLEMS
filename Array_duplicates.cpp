/*Given an array arr of integers, find all the elements that occur more than once in the array.
 If no element repeats, return an empty array.

Examples:

Input: arr[] = [2, 3, 1, 2, 3]
Output: [2, 3] 
Explanation: 2 and 3 occur more than once in the given array.
Input: arr[] = [0, 3, 1, 2] 
Output: [] 
Explanation: There is no repeating element in the array, so the output is empty.
Input: arr[] = [2]
Output: [] 
Explanation: There is single element in the array. Therefore output is empty.*/

// CODE :-
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        vector<int>duplicates;
        for(int i = 0;i<arr.size()-1;i++) {
            if(arr[i]==arr[i+1]) {
                if(duplicates.empty() || duplicates.back()!=arr[i]) {
                    duplicates.push_back(arr[i]);
                }
            }
        }
        return duplicates;
    }
};
