class Solution {
public:
    /*
     * Complexity: O(n*lg(k))
     * Space: O(k)
     *
     * Like merge k sorted list, the priority queue would always has one element
     * from each lists (k elements). Each time we pop the smallest element then
     * push the new one, there would be a new potential minimum range that cover
     * elements from all lists.
     */
    struct compare{
      bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
          return p1.first > p2.first;
      }  
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare>min_heap;
        
        vector<int>idx(nums.size(), 0);
        int max_val = INT_MIN;
        for(int i = 0; i < nums.size(); ++i){
            min_heap.push(make_pair(nums[i][0], i));
            max_val = max(max_val, nums[i][0]);
            ++idx[i];
        }
        vector<int>min_range{min_heap.top().first, max_val};
        
        while(min_heap.size() == nums.size()) {
            pair<int, int> prev_small = min_heap.top();
            min_heap.pop();
            int lst_idx = prev_small.second;
            // push new element
            if(idx[lst_idx] < nums[lst_idx].size()) {
                // push new element from the prev popped list
                min_heap.push(make_pair(nums[lst_idx][idx[lst_idx]], lst_idx));
                max_val = max(max_val, nums[lst_idx][idx[lst_idx]]);
                pair<int, int>new_smallest = min_heap.top();
                // update range
                if((max_val - new_smallest.first) < (min_range[1] - min_range[0])){
                    min_range[1] = max_val;
                    min_range[0] = new_smallest.first;
                } 
                ++idx[lst_idx];
                
            } else {
                break;
            }
        }
        return min_range;
    }
};
