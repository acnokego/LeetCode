class Solution {
/*
 * Complexity: O(n^2)
 * Space: O(1) no extra space
 * Achieving rotation by using reflection:
 * https://en.wikipedia.org/wiki/Coordinate_rotations_and_reflections
 */
public:
    // reverse each colum matrix 
    void mirror(vector<vector<int>>& matrix, int n) {
        int mid = n / 2;
        int tmp;
        for(int i = 0; i < mid; ++i){
            for(int j = 0; j < n; ++j){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-i][j];
                matrix[n-1-i][j] = tmp;
            }
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0 || n == 1) return;
        mirror(matrix, n);
        int tmp;
        // swap with symmetry
        for(int i = 0; i < n; ++i){
            for(int j = i+1; j < n; ++j){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};
