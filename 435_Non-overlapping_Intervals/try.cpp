class Solution {
public:
    /*
     * Complexity: O(nlgn)
     * Space: O(1)
     */
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){
            return (a[0] == b[0]) ? a[1] < b[1] : a[0] < b[0];
        });
        
        int ans = 0;
        int size = intervals.size();
        if(!size) return 0;
        int prev_end = intervals[0][1];
        for(int i = 1; i < size; ++i){
            if(prev_end > intervals[i][0]){
                ++ans;
                if(prev_end > intervals[i][1]){
                    prev_end = intervals[i][1];
                }
            } else{
                prev_end = intervals[i][1];
            }
        }
        return ans;
    }
};
