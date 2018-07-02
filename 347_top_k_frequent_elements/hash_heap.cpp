class Solution {
  /*
   * Complexity: O(nlgn)
   * Space: O(n)
   */
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == 0) return nums;
        unordered_map<int, int>occur;
        for(auto num : nums){
            ++occur[num];
        }
        vector<int>ans;
        priority_queue< pair<int, int>  > q;
        for(auto it : occur){
            // the operator compare the first value of pair
            q.push({it.second, it.first});
        }
        for(int i = 0; i< k; ++i){
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};   
