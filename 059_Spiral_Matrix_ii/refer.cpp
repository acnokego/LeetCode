class Solution {
  /*
   * Complexity: O(n^2)
   * Space: O(1)
   */
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n, vector<int>(n));
        if(!n) return ans;
        int row = 0, col = 0;
        int count = 1, spiral_loop = 0;
        
        while(count <= n*n){
            
            row = spiral_loop;
            col = spiral_loop;
            // go right
            while(col <= n - 1 - spiral_loop){
                ans[row][col++] = count++;
            }
            row += 1; --col;
            // go down
            while(row <= n - 1 - spiral_loop){
                ans[row++][col] = count++;
            }
            col -= 1; --row;
            // go left
            while(col >= spiral_loop){
                ans[row][col--] = count++;   
            }
            
            row -= 1; ++col;
            ++spiral_loop;
            // go up
            while(row >= spiral_loop){
                ans[row--][col] = count++;
            }
            
        }
        
        return ans;
    }
};
