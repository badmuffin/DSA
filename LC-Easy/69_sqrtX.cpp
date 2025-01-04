/*
69. Sprt(x) - Easy
-------------------

Given a non-negative integer x, return the square root 
of x rounded down to the nearest integer. The returned 
integer should be non-negative as well.

You must not use any built-in exponent function or 
operator.

For example, do not use pow(x, 0.5) in c++ or 
x ** 0.5 in python.

-------------------
Example 1 - 
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., 
and since we round it down to the nearest integer, 2 is returned.
*/

#include <iostream>
using namespace std;

int mySqrt(int x) {
  if (x == 0 || x == 1) return x;

  int left = 1, right = x;
  int result = 0;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (mid * mid == x) {
      result = mid;
      break;
    } else if (mid * mid < x) {
      result = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return result;
}