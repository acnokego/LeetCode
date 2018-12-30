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
 * Complexity: O(n)
 * Space: O(1)
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>ans;
        
        
        bool push_new = false;
        // push the interval one by one
        for(int i = 0; i < intervals.size(); ++i){
            Interval interval = intervals[i];
            Interval to_pushed;
            
            // push new interval first, the current interval is after newInterval
            if(!push_new && interval.start > newInterval.end){
                to_pushed = Interval(newInterval.start, newInterval.end);
                --i;
                push_new = true;
            }
            // if not overlap
            else if(interval.end < newInterval.start || interval.start > newInterval.end){
                to_pushed = Interval(interval.start, interval.end);
            }
            // merge the interval with newInterval
            else{
                to_pushed = Interval(min(interval.start, newInterval.start), max(interval.end, newInterval.end));
                push_new = true;
            }
            
            // if it can be merged to the previous interval
            if(ans.size() && ans.back().end >= to_pushed.start){
                ans.back().end = max(to_pushed.end, ans.back().end); 
            }
            else ans.push_back(to_pushed);

        }
        
        // fix corner case
        if(!intervals.size() || ans.back().end < newInterval.start){
            ans.push_back(newInterval);
        }
        return ans;
    }
};
