/*
Print GFG n times without the loop.

Example:

Input:
5
Output:
GFG GFG GFG GFG GFG
Your Task:
This is a function problem. You only need to complete the function printGfg() that takes N as parameter and prints N times GFG recursively. 
Don't print newline, it will be added by the driver code.


Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N) (Recursive).

Constraint:
1<=N<=1000
*/
#include<iostream>
using namespace std;

class Solution {
  public:
    void printGfg(int N) {
        // Code here
        if(N==0)
        {
            return;
        }
        cout<<"GFG"<<" ";
        printGfg(N-1);
    }
};
