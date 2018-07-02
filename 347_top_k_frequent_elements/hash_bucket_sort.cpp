class Solution {
  /*
   * Complexity: O(n)
   * Space: O(n)
   * create bucket according to its frequency.
   * then push value from the last bucket.
   */
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>occur;
        for(auto num : nums){
            ++occur[num];
        }
        vector< vector<int> >bucket(nums.size()+1);
        for(auto it : occur){
            bucket[it.second].push_back(it.first);
        }
        vector<int>ans;
        for(int i = bucket.size()-1; i >= 0; --i){
            for(int j = 0; j < bucket[i].size(); ++j){
                ans.push_back(bucket[i][j]);
                if(ans.size() == k) return ans;
            }
        }
    }
};       
