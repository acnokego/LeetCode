class Solution {
public:
    /*
     * Complexity: O(N) number in days array
     * Space: O(N)
     */
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        queue<pair<int,int>> last7, last30;
        
        int cost = 0;
        for(int& day : days){
            // pop the expired day
            while(!last7.empty() && (last7.front().first + 7) <= day) last7.pop();
            while(!last30.empty() && (last30.front().first + 30) <= day) last30.pop();
            last7.push({day, cost + costs[1]}); // cost before the current day + the 7-day pass start today
            last30.push({day, cost + costs[2]});
            cost = min({ cost + costs[0], last7.front().second, last30.front().second}); //buy new one day, use the previous 7-day/30-day
        }
        return cost;
    }
};
