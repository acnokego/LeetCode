class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int>occur;
        for(int i = 0; i < nums.size(); ++i){
            auto it = occur.find(nums[i]);
            if(it != occur.end()) it->second += 1;
            else occur.insert({nums[i], 1});
        }
        for(auto it = occur.begin();it != occur.end(); ++it){
            if(it->second == 1) return it->first;
        }
        return 0;
    }
};
