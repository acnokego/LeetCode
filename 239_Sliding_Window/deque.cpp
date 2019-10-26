class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(k)
     */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        for(int i = 0; i < nums.size(); ++i){
            // the element is out of the window
            if(!dq.empty() && dq.front() == i - k) dq.pop_front();
            // nums[back] < nums[i], it has no chance to be the maximum in the window.
            while(!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
            dq.push_back(i);
            if(i >= k - 1) ans.push_back(nums[dq.front()]); // the element smaller than front would be popped, so the front is the bigger one in the current window.
        }
        return ans;
    }
};
