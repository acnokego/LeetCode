class Solution {
public:
    /*
     * Complexity: O(WlogD)
     * Space: O(D)
     */
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        map<int, int>diff_max_profit;
        // O(DlogD)
        for(int i = 0; i < difficulty.size(); ++i){
            if(diff_max_profit.count(difficulty[i])){
                diff_max_profit[difficulty[i]] = max(diff_max_profit[difficulty[i]], profit[i]);
            } else {
                diff_max_profit[difficulty[i]] = profit[i];
            }

        }
        // O(D)       
        int max_profit = 0;
        for(auto it = diff_max_profit.begin(); it != diff_max_profit.end(); ++it){
            if(it -> second > max_profit){
                max_profit = it -> second;
            }
            it -> second = max_profit;
        }
        
        int ans = 0;
        // O(WlogD)
        for(int i = 0; i < worker.size(); ++i){
            auto max_pro = diff_max_profit.lower_bound(worker[i]);
            if(max_pro == diff_max_profit.end() || max_pro -> first != worker[i]){
                ans += (--max_pro) -> second;
            } else {
                ans += (max_pro -> second);
            }
        }
        return ans;
    }
};
