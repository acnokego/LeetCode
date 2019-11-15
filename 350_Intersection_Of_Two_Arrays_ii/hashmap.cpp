class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>occur1;
        unordered_map<int, int>occur2;
        
        for(int num : nums1){
            occur1[num] += 1;
        }
        
        for(int num : nums2){
            occur2[num] += 1;
        }
        
        vector<int>ans;
        
        for(auto ele : occur1){
            if(occur2.count(ele.first)){
                int intersect_time = min(ele.second, occur2[ele.first]);
                for(int i = 0; i < intersect_time; ++i){
                    ans.push_back(ele.first);
                }
            }
        }
        return ans;
    }
};
