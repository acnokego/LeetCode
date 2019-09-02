class Solution {
public:
    /*
     * Complexity: O(m + n)
     * Space: O(1)
     *
     * Two ptrs, one for the vector A, the other for vector B.
     */
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<vector<int>>ans;
        int B_idx = 0, B_size = B.size();
        for(auto interval_a : A) {
            while(B_idx < B_size){
                auto interval_b = B[B_idx];
                // intersect with current B interval
                // ** we can actually just check a.end and b.end and assign the
                // ** interval based on a.start > b.start or not.
                // a inside b
                bool case1 = (interval_a[0] >= interval_b[0] && interval_a[1] <= interval_b[1]);
                // b inside a
                bool case2 = (interval_a[0] <= interval_b[0] && interval_a[1] >= interval_b[1]);
                // a start earlier, b start earlier than a end
                bool case3 = (interval_a[0] <= interval_b[0] && interval_a[1] >= interval_b[0]);
                // b start earlier, a start earlier than b end
                bool case4 = (interval_b[0] <= interval_a[0] && interval_b[1] >= interval_a[0]);
                if(case1) {
                    ans.push_back(vector<int>(interval_a));
                    break;
                    
                } else if (case2) {
                    ans.push_back(vector<int>(interval_b));
                    ++B_idx;
                } else if (case3){
                    ans.push_back(vector<int>({interval_b[0], interval_a[1]}));
                    break;
                } else if (case4) {
                    ans.push_back(vector<int>{{interval_a[0], interval_b[1]}});
                    ++B_idx;
                } else {
                    if(interval_a[1] < interval_b[0]) break;
                    else ++B_idx;
                }
            }
        }
        return ans;
    }
};
