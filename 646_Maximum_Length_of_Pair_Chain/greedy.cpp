class Solution {
public:
    /*
     * Complexity: O(nlgn)
     * Space: O(1)
     *
     * sort the pair by its end, so that we can have the pair that end the
     * earliest at the first. (maximum job can fit)
     */
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),[](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
            
        });
        
        int size = pairs.size();
        if(!size) return 0;
        int max_len = 1, prev_end = pairs[0][1];
        for(int i = 0; i < size; ++i){
            if(pairs[i][0] > prev_end){
                ++max_len;
                prev_end = pairs[i][1];
            }   
        }
        return max_len;
    }
};
