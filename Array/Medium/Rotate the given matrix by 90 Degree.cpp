// Problem: Rotate a given N x N matrix by 90 degrees (clockwise).
// Approach: 
// 1. Transpose the matrix.
// 2. Reverse each row of the transposed matrix to get the rotated version.

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();  // Size of the matrix (n x n)

        // Step 1: Transpose the matrix
        // We swap matrix[i][j] with matrix[j][i] for i < j to get the transpose.
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row to complete the 90-degree clockwise rotation
        for(int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

/*
Explanation:
- The first nested loop transposes the matrix by swapping elements across the diagonal.
- The second loop reverses each row of the transposed matrix to achieve the 90-degree rotation.
For example, if the matrix is:
    1  2  3
    4  5  6
    7  8  9

After transposition, it becomes:
    1  4  7
    2  5  8
    3  6  9

After reversing each row, it becomes:
    7  4  1
    8  5  2
    9  6  3
This is the final 90-degree rotated matrix.
*/

