class Solution {
public:
    static bool comp(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == 0) return nums;
        unordered_map<int, int>occur;
        for(auto num : nums){
            auto it = occur.find(num);
            if(it != occur.end())occur[num] += 1;
            else occur.insert({num, 1});
        }
        vector< pair<int, int> > occur_v(occur.begin(), occur.end());
        sort(occur_v.begin(), occur_v.end(), comp);
        vector<int> ans;
        for(int i = 0; i < k; ++i){
            ans.push_back(occur_v[i].first);
        }
        return ans;
    }
};
