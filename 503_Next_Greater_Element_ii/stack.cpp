class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int s = nums.size();
        vector<int>ans(s, -1);
        // use stack to store the idx of next elements
        stack<int>next_idx;
        if(s){
            // do it reversely, so that the idx would be popped in order
            for(int i = s-1; i >= 0; -- i){
                next_idx.push(i);
            }
            // do it reversely. because when we finish checking an element
            // this element should be pushed to the stack, and it be on the
            // top (the first next element of next iteration)
            for(int i = s-1; i >= 0; --i){
                while(!next_idx.empty() && nums[next_idx.top()] <= nums[i]){
                    next_idx.pop();
                }
                if(!next_idx.empty()) ans[i] = nums[next_idx.top()];
                next_idx.push(i);
            }
            
        }
        return ans;
    }
};
