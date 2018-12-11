class Solution {
  /*
   * Complexity: O(N!)
   * Space: O(N)
   */
public:
    void recursive(int N, int idx, vector<bool>& used, int& ans){
        if(idx > N){
            ans += 1;
            return;
        }
        // try each permutation.
        for(int i = 1; i <= N; ++i){
            if(!used[i]){
                // match the beautiful arrangement for each idx
                if((idx > i && idx % i == 0) || ( idx <= i && i % idx == 0)){
                    used[i] = true;
                    recursive(N, idx + 1, used, ans);
                    used[i] = false;
                }
            }
        }
        return;
    }
    int countArrangement(int N) {
        
        int ans = 0;
        vector<bool>used(N+1, false);
        recursive(N, 1, used, ans);
        return ans;
    }
};
