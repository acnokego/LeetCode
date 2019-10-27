class Solution {
public:
    /*
     * Complexiry: O(nlgn), can make it O(n) by finding only the maximum 3 and
     * minimum 2.
     * Space: O(1)
     */
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        return max(nums[0]*nums[1]*nums[len-1], nums[len-1]*nums[len-2]*nums[len-3]);
    }
};
