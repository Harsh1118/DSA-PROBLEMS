/*
You are given two arrays, color and radius, representing a sequence of balls:


color[i] is the color of the i-th ball.
radius[i] is the radius of the i-th ball.

If two consecutive balls have the same color and radius, remove them both. Repeat this process until no more such pairs exist.


Return the number of balls remaining after all possible removals.

Examples:

Input: color[] = [2, 3, 5], radius[] = [3, 3, 5]
Output: 3
Explanation: All the 3 balls have different colors and radius.
Input: color[] = [2, 2, 5], radius[] = [3, 3, 5]
Output: 1
Explanation: First ball and second ball have same color 2 and same radius 3. So, after removing only one ball is left. It cannot be removed 
from the array. Hence, the final array has length 1.
Constraints:
1 ≤ color.size() = radius.size() ≤ 105
1 ≤ color[i] ≤ 109
1 ≤ radius[i] ≤ 109                                                                                                                                           

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)
*/

#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<int>col;
        stack<int>rad;
        
        col.push(color[0]);
        rad.push(radius[0]);
        
        int i = 1;
        while(i<color.size())
        {
         if(!col.empty() && !rad.empty() && color[i]==col.top() && radius[i]==rad.top())
            {
                col.pop();
                rad.pop();
            }
            else
            {
                col.push(color[i]);
                rad.push(radius[i]);
            }
            i++;
        }
        return col.size();
    }
};