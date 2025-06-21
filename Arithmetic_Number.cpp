/*
Given three integers  'a' denotes the first term of an arithmetic sequence, 'c' denotes the common difference of an 
arithmetic sequence and an integer 'b'. you need to tell whether 'b' exists in the arithmetic sequence or not. 
Return 1 if b is present in the sequence. Otherwise, returns 0.

Examples:

Input: a = 1, b = 3, c = 2
Output: true
Explaination: 3 is the second term of the sequence starting with 1 and having a common difference 2.
Input: a = 1, b = 2, c = 3
Output: false
Explaination: 2 is not present in the sequence.
Input: a = 1, b = 2, c = 4
Output: false
Explaination: 2 is not present in the sequence.
Constraints:
-109 ≤ a, b, c ≤ 109  

Expected Complexities
Time Complexity: O(1)
Auxiliary Space: O(1)
*/

#include<iostream>
using namespace std;

class Solution {
  public:
    int inSequence(int a, int b, int c) {
        // code here
        int r = (b-a)/c;
        if(a+r*c==b)
        {
            return true;
        }
        return false;
    }
};