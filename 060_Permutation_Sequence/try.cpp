class Solution {
  /*
   * Complexity: O(n*k)
   * Space: O(n)
   */
public:
    void getNextPermutation(vector<int>& nums){
        
        int n = nums.size();
        if(n <= 1) return;
        
        int reverse_idx = (n - 2);
        
        while(reverse_idx >= 0 && nums[reverse_idx + 1] <= nums[reverse_idx]){
            --reverse_idx;
        }
        
        if(reverse_idx >= 0){
            for(int i = n - 1; i > reverse_idx; --i){
                if(nums[i] > nums[reverse_idx]){
                    swap(nums[i] , nums[reverse_idx]);
                    break;
                }
            }
        }
        
        sort(nums.begin() + reverse_idx + 1, nums.end());
        
    }
    string getPermutation(int n, int k) {
        
        if(!n) return string();
        
        vector<int>permutation(n);
        
        for(int i = 0; i < n; ++i){
            permutation[i] = i + 1;
        }
        
        for(int i = 2; i <= k; ++i){
            getNextPermutation(permutation);
        }
        
        string ans;
        
        for(int& i : permutation){
            ans += (char)('0' + i);
        }
        return ans;
    }
};
