/*Given an array arr. Find the majority element in the array. If no majority exists, return -1.

A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.

Examples:

Input: arr[] = [3, 1, 3, 3, 2]
Output: 3
Explanation: Since, 3 is present more than n/2 times, so it is the majority element.
Input: arr[] = [7]
Output: 7
Explanation: Since, 7 is single element and present more than n/2 times, so it is the majority element.
Input: arr[] = [2, 13]
Output: -1
Explanation: Since, no element is present more than n/2 times, so there is no majority element.
*/

// CODE :-
// The approach i am using is also known as "Moore Voting Algorithm".
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
// your code here
        int n = arr.size();
        int candidate = 0 , count = 0;
        for(int i = 0; i<n;i++) {
            if(count == 0) {
                count = 1;
                candidate = arr[i];
            }
            else {
                if(candidate == arr[i]) {
                    count++;
                }
                else {
                    count--;
                }
            }
        }
        count = 0;
        for(int i = 0;i<n;i++) {
            if(arr[i]==candidate) {
                count++;
            }
            if(count > n/2) {
                return candidate;
            }
        }
        return -1;
    }
}; 
