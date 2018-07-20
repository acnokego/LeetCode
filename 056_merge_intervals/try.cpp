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
 * Complexity: average-case(only half can be merged) O(nlgn), worst-case O(n^2)
 * Space: O(n)
 */
class Solution {
public:
    void push_interval(Interval& new_inter, vector<Interval>& ans){
        ans.push_back(new_inter);
        int n = ans.size();
        int last_merge_idx = n - 1;
        for(int i = n - 2; i >= 0; --i){
            // new interval merge from back
            if(ans[i].start <= new_inter.start){
                if(ans[i].end >= new_inter.start){
                    ans[i].end = (ans[i].end > new_inter.end ? ans[i].end : new_inter.end);
                    // update new interval
                    new_inter.start = ans[i].start;
                    new_inter.end = ans[i].end;
                    // pop the previous merge one
                    ans[last_merge_idx] = ans.back();
                    ans.pop_back();
                    last_merge_idx  = i;
                }
                // no interval
                else continue;
            }
            else{
                if(ans[i].start <= new_inter.end){
                    ans[i].start = new_inter.start;
                    ans[i].end = (ans[i].end > new_inter.end ? ans[i].end : new_inter.end);
                    // update new interval
                    new_inter.start = ans[i].start;
                    new_inter.end = ans[i].end;
                    // pop the previous merge one
                    ans[last_merge_idx] = ans.back();
                    ans.pop_back();
                    last_merge_idx  = i;
                }
                // no interval
                else continue;
            }
        }
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        for(auto& inter : intervals){
            push_interval(inter, ans);
        }
        return ans;
    }
};
