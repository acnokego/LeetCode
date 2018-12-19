class Solution {
  /*
   * Complexity: O(m*n)
   * Space: O(n)
   */
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int maxArea = 0;
        if(m){
            int n = matrix[0].size();
            vector<int>h(n, 0);
            
            for(int i = 0; i < m; ++i){
                
                // for each row apply alg in "Largest Rectangle in Histogram"
                stack<int>s;
                for(int j = 0; j <= n; ++j){
                    
                    // update height for each row
                    if(j != n){
                        if(matrix[i][j] == '1'){
                            h[j] += 1;
                        }
                        else h[j] = 0;
                             
                    }
               
                    // current histogram
                    int height = ((j == n) ? 0 : h[j]);
                    
                    // increasing order
                    if(s.empty() || height >= h[s.top()]){
                        s.push(j);
                    }
                    else{
                        while(!s.empty() && height < h[s.top()]){
                            int lowest = s.top();
                            s.pop();
                            maxArea = max(maxArea, h[lowest] * ( s.empty() ? j : j - 1 - s.top() ));
                        }
                        s.push(j);
                    }
                }
            }
            
        }
        return maxArea;
    }
};
