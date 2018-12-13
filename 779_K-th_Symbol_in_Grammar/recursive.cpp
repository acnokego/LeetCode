class Solution {
  /*
   * Complexity: O(N)
   * Space: O(N)
   */
public:
    int recursive(int row, int col){
        if(row == 0) return 0; 
        // get the value in previous row that generate the value in current row
        int prev_row = recursive(row - 1, col/2);
        // get the current value accourding to the rule
        return (prev_row) ? ((col % 2 == 0) ? 1 : 0) : ((col % 2 == 0) ? 0 : 1);
    }
    int kthGrammar(int N, int K) {
        
        // starting from idx 0
        return recursive(N - 1, K - 1);
    }
};
