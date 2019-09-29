class Solution {
public:
    /*
     * Complexity: O(nlgn)
     * Space: O(n)
     */
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        // sort envelopes in the Ascending order of width, descending order of
        // height (LIS not count elements of the same width)
        sort(envelopes.begin(), envelopes.end(), [](const auto& e1, const auto& e2){
            if(e1[0] == e2[0]) return e1[1] > e2[1];
            return e1[0] < e2[0];
        });
        
        
        // LIS on height
        vector<int>LIS;
        
        for(auto e : envelopes) {
            auto replace = lower_bound(LIS.begin(), LIS.end(), e[1]);
            if(replace != LIS.end()){
                *replace = e[1];
            } else {
                LIS.push_back(e[1]);
            }
        }
        return LIS.size();
    }
};
