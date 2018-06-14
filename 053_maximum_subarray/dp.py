class Solution:
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        """
        Complexity: O(n)
        Space: O(n)
        let dp[i] be the maximum subarray ending at the ith index.

        If we use Divide and Conquer the complexity becomes(nlogn),
        logn for binary search, n for the maximum subarray cross the left and right

        """
        dp = [0]*len(nums)
        dp[0] = nums[0]
        max_value = dp[0]
        for i in range(1, len(nums)):
            dp[i] = dp[i-1] + nums[i] if dp[i-1] > 0 else nums[i]
            max_value = max(max_value, dp[i])
            
        return max_value
            
