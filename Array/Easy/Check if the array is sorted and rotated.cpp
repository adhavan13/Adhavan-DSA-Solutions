/*
    Problem: 1752. Check if Array Is Sorted and Rotated
    Description:
    You are given an array 'nums'. We need to check whether this array is a 
    rotated version of a sorted array. A sorted array rotated at some pivot
    means it can be transformed into a sorted array by shifting some elements
    from the front to the back.
    
    Approach:
    1. Iterate through the array to find the index where the sorting breaks.
    2. Store the index of the break.
    3. Check if rotating the array at the break index results in a sorted array.

    Time Complexity: O(n log n) due to the sorting step.
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int x = 0;  // Variable to store the index where sorting breaks
        int len = nums.size();
        
        // Identify the break point where the array is no longer sorted
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                x = i + 1;
            }
        }

        // Copy the original array for comparison later
        vector<int> original(nums);

        // Sort the original array
        sort(nums.begin(), nums.end());

        // Check if the sorted array can be obtained by rotating the original array
        for (int i = 0; i < len; i++) {
            if (nums[i] != original[(i + x) % len]) {
                return false;
            }
        }

        return true;
    }
};
