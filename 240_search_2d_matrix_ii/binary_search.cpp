class Solution {
public:
    bool binary_search(vector<int>& row, int start, int end, int target){
        while(start <= end){
            int mid = (end - start + 1) / 2;
            if(row[start + mid] == target) return true;
            else if(start == end) return false;
            if(row[start + mid] > target) end = start+mid-1;
            else start = start+mid;
        }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        int n_col = matrix[0].size();
        for(int i = 0; i < matrix.size(); ++i){
            if(matrix[i][0] <= target && matrix[i][n_col-1] >= target){
                if(binary_search(matrix[i], 0, n_col-1, target)) return true;
            }
            else continue;
        }
        return false;
    }
};
