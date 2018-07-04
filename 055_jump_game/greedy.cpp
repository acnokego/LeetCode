class Solution {
/*
 * Complexity: O(n)
 * Space: O(1)
 * Start from the end of the nums to the first element. if the current element
 * could reach the previous leftmost element, it means that the current idx is 
 * smaller than the previous one and we then update it. Eventually, we check if
 * the leftmost index we could reach is 0 or not.
 */
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int leftmost = n - 1;
        for(int i = n - 2; i >= 0; --i){
            if(nums[i] + i >= leftmost) leftmost = i;
        }
        return (leftmost == 0);
    }
};
