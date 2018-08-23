class Solution {
  /*
   * Complexity: O(n)
   * Space: O(1)
   */
public:
    void nextPermutation(vector<int>& nums) {
        int s = nums.size();
        if(s == 0) return;
        int k;
        // start from the low order digit
        // the array[k+1..s-1] is reversely sorted
        // which means it is the biggest permutation we can have if we fix the nums[0..k]
        // if we want to get the next permutation we need to modify nums[k]
        for(k = s - 2; k >= 0; --k){
            if(nums[k] < nums[k+1])break;
        }
        if(k == -1) return;
        int l;
        // swap nums[k] with the smallest number in nums[k+1..s-1] that is larger than nums[k]
        // since we want the increasing amount be the smallest.
        for(l = s - 1; l > k; --l){
            if(nums[l] > nums[k]) break;
        }
        swap(nums[k], nums[l]);
        // then we reverse the reversely sorted array to make nums[k+1..s-1] become the smallest.
        reverse(nums.begin()+k+1, nums.end());
    }
};
