// Problem: Given a matrix, return all elements of the matrix in spiral order.
// Approach:
// 1. Traverse the matrix from the outermost elements inward in a spiral pattern.
// 2. Move from left to right along the top row, then top to bottom along the right column, 
//    then right to left along the bottom row, and finally bottom to top along the left column.
// 3. Repeat the process until all elements are traversed.

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;  // To store the result in spiral order
        if(matrix.empty()) return ans;  // Edge case: empty matrix

        // Define the boundaries of the matrix
        int top = 0;                      // Top boundary
        int bottom = matrix.size() - 1;    // Bottom boundary
        int left = 0;                      // Left boundary
        int right = matrix[0].size() - 1;  // Right boundary

        // Loop until all elements are added to the result
        while(top <= bottom && left <= right) {

            // Traverse from left to right along the top row
            for(int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;  // Move the top boundary down

            // Traverse from top to bottom along the right column
            for(int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;  // Move the right boundary to the left

            // Traverse from right to left along the bottom row (if rows remain)
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;  // Move the bottom boundary up
            }

            // Traverse from bottom to top along the left column (if columns remain)
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;  // Move the left boundary to the right
            }
        }

        return ans;  // Return the spiral order of the matrix
    }
};

/*
Explanation:
- The matrix is traversed in a spiral manner by repeatedly adjusting the boundaries.
- We start from the top-left corner, moving to the right, then downward, then to the left, and finally upward.
- The boundaries (top, bottom, left, right) are adjusted as we traverse each row and column.
- This process continues until all elements of the matrix are covered.
- Edge cases like an empty matrix or single row/column are handled by the boundary checks.

Example:
For the matrix:
    1   2   3
    4   5   6
    7   8   9

The output will be: [1, 2, 3, 6, 9, 8, 7, 4, 5]

*/
