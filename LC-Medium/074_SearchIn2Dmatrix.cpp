/*
74. Search a 2D Matrix
----------------------

You are given an m x n integer matrix matrix with the
following two properties:
  -> Each row is sorted in non-decreasing order.
  -> The first integer of each row is greater than the last
     integer of the previous row.
Given an integer target, return true if target is in matrix
or false otherwise.

You must write a solution in O(log(m * n)) time
complexity.

----------------------
Example:
  Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]],
         target = 3
  Output: true
*/

#include <iostream>
#include <vector>
using namespace std;

// TC - O(N*log(M))
class Solution
{
private:
  bool binarySearch(vector<int> arr, int target)
  {
    int left = 0;
    int right = arr.size() - 1;
    int mid = 0;

    while (left <= right)
    {
      mid = left + (right - left) / 2;
      if (target == arr[mid])
        return true;
      else if (target > arr[mid])
        left = mid + 1;
      else
        right = mid - 1;
    }
    return false;
  }

public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
      if (target >= matrix[i][0] && target <= matrix[i][m - 1])
        return binarySearch(matrix[i], target);
    }
    return false;
  }
};


// -------------------------------------------
// TC - O(log(m * n))
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
  int n = matrix.size();
  int m = matrix[0].size();
  int low = 0, high = n * m - 1, mid = 0;

  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    // deriving relation between 1d coordinate and 2d coordinate
    int row = mid / m;
    int col = mid % m;

    if (matrix[row][col] == target)
      return true;
    else if (matrix[row][col] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return false;
}