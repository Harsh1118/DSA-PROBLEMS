/*Given an array arr[] denoting the cost of stock on each day, the task is to find the maximum total profit if we can buy and sell the stocks any number of times.

Note: We can only sell a stock which we have bought earlier and we cannot hold multiple stocks on any day.

Examples:

Input: arr[] = [100, 180, 260, 310, 40, 535, 695]
Output: 865
Explanation: Buy the stock on day 0 and sell it on day 3 => 310 – 100 = 210 Buy the stock on day 4 and sell it on day 6 => 695 – 40 = 655 Maximum Profit  = 210 + 655 = 865
Input: arr[] = [4, 2, 2, 2, 4]
Output: 2
Explanation: Buy the stock on day 3 and sell it on day 4 => 4 – 2 = 2
Input: arr[] = [4, 2]
Output: 0
Explanation: Don't Buy the stock.*/

// CODE HERE :-
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:

      int stockBuySell(vector<int> &arr) {
        
          int n = arr.size();
          int final_profit = 0;
          
          if(n<2) {
              return 0;
          }
          for(int i = 0; i<n-1; i++) {
              if(arr[i]<arr[i+1]) {
                  final_profit += arr[i+1]-arr[i];
              }
          }
          return final_profit;
          
      }
  };