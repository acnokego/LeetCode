class Solution {
public:
    /*
     * Complexity: O(nlgk)
     * Space: O(k)
     */
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int>window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        vector<double>ans;
        for(int i = k; i < nums.size(); ++i){
            ans.push_back((double(*mid) + *prev(mid, 1-k%2)) / 2);
            window.insert(nums[i]);
            // insert
            if(*mid > nums[i]){
                --mid;
            } 
            // erase
            if( *mid >= nums[i-k]){
                ++mid;
            } 
            
            window.erase(window.lower_bound(nums[i-k]));
        }
        ans.push_back((double(*mid) + *prev(mid, 1-k%2)) / 2);;
        return ans;
    }
};
