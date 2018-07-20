/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
/*
 * Complexity: O(nlgn)
 * Space: O(n)
 */
class Solution {
public:
  
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<Interval> ans;
        if(n == 0) return ans;
        // using lambda function to sort the intervals according to its start 
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){return a.start < b.start;});
        ans.push_back(intervals[0]);
        // once the start has been sorted, we could directly merge interval to
        // the end of ans.
        for(int i = 1; i < n; ++i){
            if(ans.back().end >= intervals[i].start) ans.back().end = max(intervals[i].end, ans.back().end);
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};
