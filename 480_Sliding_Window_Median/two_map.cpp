class Solution {
public:
    /*
     * Complexity: O(nlgk)
     * Space: O(k)
     */
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        vector<double>ans;
        map<int, int>max_half; // one more element than min_half
        map<int, int, greater<int>>min_half;
        
        // init
        for(int i = 0; i < k; ++i){
            if(!max_half.count(nums[i])){
                max_half.insert(make_pair(nums[i], 1));
            } else max_half[nums[i]] += 1;
        }
        
        // push minimum half to to the min_half
        int half = k / 2;
        auto it = max_half.begin();
        for (int i = 0; i < half; ++i){
            if(!min_half.count(it->first)){
                min_half.insert(make_pair(it->first, 1));
            } else min_half[it->first] += 1;
            if(it -> second > 1){
                it -> second -= 1;
            } else {
                max_half.erase(it++);
            }
        }
        //cout << "min_last: " << min_half.begin() -> first << ", max_first: " << max_half.begin() -> first << endl;
        if (k % 2 == 0){
            ans.push_back((double(min_half.begin() -> first) + double(max_half.begin() -> first)) / 2);
        } else {
            ans.push_back(max_half.begin() -> first);
        }
        
        for(int i = k; i < nums.size(); ++i){
            // remove the element
            if(min_half.count(nums[i-k])){
                if(min_half[nums[i-k]] > 1){
                    min_half[nums[i-k]] -= 1;
                } else {
                    min_half.erase(nums[i-k]);
                }
                // push the curr to the max_half and pop the min to min+half
                if(max_half.count(nums[i])){
                    max_half[nums[i]] += 1;
                } else {
                    max_half.insert(make_pair(nums[i], 1));
                }
                
                auto max_first = max_half.begin();
                if(min_half.count(max_first -> first)){
                    min_half[max_first->first] += 1;
                } else {
                    min_half.insert(make_pair(max_first->first, 1));
                }
                if(max_first -> second > 1){
                    max_first -> second -= 1;
                } else {
                    max_half.erase(max_first);
                }
            } else {
                if(max_half[nums[i-k]] > 1){
                    max_half[nums[i-k]] -= 1;
                } else {
                    max_half.erase(nums[i-k]);
                }
                // push the curr to the min_half anf pop the max to max_half
                if(min_half.count(nums[i])){
                    min_half[nums[i]] += 1;
                } else {
                    min_half.insert(make_pair(nums[i], 1));
                }
                
                auto min_last = min_half.begin();
                // add
                if(max_half.count(min_last -> first)){
                    max_half[min_last->first] += 1;
                } else {
                    max_half.insert(make_pair(min_last->first, 1));
                }
                // pop
                if(min_last -> second > 1){
                    min_last -> second -= 1;
                } else {
                    min_half.erase(min_last);
                } 
            }
            //cout << "min_last: " << min_half.begin() -> first << ", max_first: " << max_half.begin() -> first << endl; 
            if (k % 2 == 0){
                ans.push_back((double(min_half.begin() -> first) + double(max_half.begin() -> first)) / 2);
            } else {
                ans.push_back(max_half.begin() -> first);
            }
        }
        return ans;
    }
};
