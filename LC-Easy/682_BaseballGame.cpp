/*
682. Baseball Game
------------------
Input: ops = ["5","-2","4","C","D","9","+","+"]
Output: 27
Explanation:
"5" - Add 5 to the record, record is now [5].
"-2" - Add -2 to the record, record is now [5, -2].
"4" - Add 4 to the record, record is now [5, -2, 4].
"C" - Invalidate and remove the previous score, record is now [5, -2].
"D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
"9" - Add 9 to the record, record is now [5, -2, -4, 9].
"+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
"+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int calPoints(vector<string>& operations) {
  stack<int> st;

  for(int i=0; i<operations.size(); i++) {
    if(operations[i] == "+") {
      int val1 = st.top();
      st.pop();
      int val2 = st.top();

      st.push(val1);
      st.push(val2);
      st.push(val1 + val2);
    } 
    else if(operations[i] == "D")
      st.push(2 * st.top());
    else if(operations[i] == "C")
      st.pop();
    else 
      st.push(stoi(operations[i]));
  }

  int record = 0;
  while(!st.empty()) {
    record += st.top();
    st.pop();
  }

  return record;
}