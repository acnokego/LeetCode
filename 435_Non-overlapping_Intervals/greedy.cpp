class Solution {
public:
    /*
     * Complexity: O(nlgn)
     * Space: O(1)
     *
     * Like finding the maximum number of non-overlapped events that can be sceduled
     */
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        
        int ans = 0;
        int size = intervals.size();
        if(!size) return 0;
        int prev_end = intervals[0][1];
        for(int i = 1; i < size; ++i){
            if(prev_end <= intervals[i][0]){
                prev_end = intervals[i][1];
            } else ++ans;
        }
        return ans;
    }
};
