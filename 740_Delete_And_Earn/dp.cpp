class Solution {
public:
    /*
     * Complexity: O(n), the range of values
     * Space: O(n)
     *
     * take_i is the optimal value if we consider only value from 1 to i and
     * take the i.
     * delete_i is the optimal value if we consider only value from 1 to i and
     * delete the i.
     */
    int deleteAndEarn(vector<int>& nums) {
        int n = 10000;
        vector<int>sum(n+1);
        for(int& i : nums) {
            sum[i] += i;
        }
        
        int size = nums.size();
        
        int last_delete = 0, last_take = 0;
        for(int i = 1; i <= n; ++i){
            int take_i = last_delete + sum[i];
            int delete_i = max(last_take, last_delete);
            last_take = take_i;
            last_delete = delete_i;
        }
        return max(last_take, last_delete);
    }
};
