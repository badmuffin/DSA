/*
912. Sort an Array - Easy
-------------------------
Given an array of integers nums, sort the array in ascending order 
and return it.

You must solve the problem without using any built-in functions in 
O(nlog(n)) time complexity and with the smallest space complexity 
possible.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    void mergeSort(vector<int> &nums, int start, int end)
    {
        if (start >= end)
            return; // single block

        // calculate mid value
        int mid = start + (end - start) / 2;

        // sort the left part
        mergeSort(nums, start, mid);
        // sort the right part
        mergeSort(nums, mid + 1, end);
        // merge both halves
        merge(nums, start, mid, end);
    }

    void merge(vector<int> &nums, int start, int mid, int end)
    {
        // create two half arrays
        // second parameter is not inclusive
        vector<int> leftArr(nums.begin() + start, nums.begin() + mid + 1);
        vector<int> rightArr(nums.begin() + mid + 1, nums.begin() + end + 1);

        int i = 0, j = 0, k = start;

        while (i < leftArr.size() and j < rightArr.size())
            (leftArr[i] <= rightArr[j]) ? nums[k++] = leftArr[i++] : nums[k++] = rightArr[j++];

        // add remaining element, if any
        while (i < leftArr.size())
            nums[k++] = leftArr[i++];
        while (j < rightArr.size())
            nums[k++] = rightArr[j++];
    }
};