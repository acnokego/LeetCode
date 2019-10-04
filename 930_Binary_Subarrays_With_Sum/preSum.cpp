class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(n)
     */
    int numSubarraysWithSum(vector<int>& A, int S) {
        vector<int>count(A.size() + 1, 0);
        int ans = 0;
        int preSum = 0;
        count[0] = 1;
        for(int i = 0; i < A.size(); ++i){
            preSum += A[i];
            if(preSum >= S){
                ans += count[preSum - S]; // the number of subarrays that has sum == S is equal to number of subarray starting from 0 that has sum equal to preSum - S 
            }
            count[preSum] += 1;
        }
        return ans;
    }
};
