class Solution {
public:
    /*
     * Complexity: O(n^2)
     * Space: O(n)
     */
    vector<int> countSmaller(vector<int>& nums) {
        vector<int>ans(nums.size(), 0);
        map<int, vector<int>>num_idx;
        
        for(int i = 0; i < nums.size(); ++i){
            auto start = num_idx.lower_bound(nums[i]);
            if(start != num_idx.end()){
                for(;start != num_idx.end(); ++start){
                    if(start -> first == nums[i]) continue;
                    for(int j = 0; j < start -> second.size(); ++j){
                        ans[start -> second[j]] += 1;
                    }
                }
            }
            if(!num_idx.count(nums[i])) {
                num_idx.insert(make_pair(nums[i], vector<int>{i}));
            } else {
                num_idx[nums[i]].push_back(i);
            }
        }
        return ans;
    }
};
