/*
739. Daily Temperatures
--------------------------
Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have 
to wait after the ith day to get a warmer temperature. If there is no future 
day for which this is possible, keep answer[i] == 0 instead.

Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int, int>> stk; // temp, index

        for(int i = 0; i < temperatures.size(); i++) {
            while(!stk.empty() && temperatures[i] > stk.top().first) {
                auto pair = stk.top();
                stk.pop();
                ans[pair.second] = i - pair.second;
            }
            stk.push({temperatures[i], i});
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = sol.dailyTemperatures(temperatures);

    for (int days : ans) {
        cout << days << " ";
    }
    cout << endl;
}