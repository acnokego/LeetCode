class Solution {
public:
    /*
     * Complexity: O(days.back() - days.front())
     * Space: O(days.back())
     */
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int>travel(days.begin(), days.end());
        
        vector<int>dp(days.back() + 1); //dp[i]: minimum cost used to travel before the ith day (including ith).
        for(int i = days[0]; i <= days.back(); ++i){
            if(!travel.count(i)) dp[i] = dp[i-1]; // don't need to spend money
            else{
                dp[i] = min({dp[i-1] + costs[0], dp[max(0, i-7)] + costs[1], dp[max(0, i-30)] + costs[2]});
            }
        }
        return dp.back();
    }
};
