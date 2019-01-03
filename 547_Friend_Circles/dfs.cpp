class Solution {
  /*
   * Complexity: O(n)
   * Space: O(max(n) in a circle)
   */
public:
    void recursive(int start, vector<bool>& inCircle, vector<vector<int>>& M){
        int N = M.size();
        inCircle[start] = true;
        
        for(int i = 0; i < N; ++i){
            if(i == start) continue;
            if(M[start][i] && !inCircle[i]){
                recursive(i, inCircle, M);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        
        vector<bool>inCircle(N, false); // whether the student is assigned to a circle
        int ans = 0;
        
        for(int i = 0; i < N; ++i){
            if(!inCircle[i]){
                ++ans;
                // mark all the direct/indirect friends assigned
                recursive(i, inCircle, M);
            }
        }
        return ans;
    }
};
