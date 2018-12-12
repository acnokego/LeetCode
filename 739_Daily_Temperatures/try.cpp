class Solution {
  /*
   * Complexity: O(n^2) TLE
   * Space: O(1)
   */
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int>ans(n, 0);
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(T[j] < T[i] && (ans[j] > (i-j) || !ans[j])){
                    ans[j] = i-j;
                }
            }
        }
        return ans;
    }
};
