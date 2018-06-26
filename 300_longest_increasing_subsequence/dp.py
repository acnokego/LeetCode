class Solution:
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        """
        Complexity: O(n^2)
        Space: O(n)
        """
        if nums == []:
            return 0
        dp = [1]*len(nums)
        ans = 1
        for i in range(len(nums)):
            tmp_max = float('-inf')
            for j in range(i):
                if nums[i] > nums[j] and dp[j] > tmp_max:
                    tmp_max = dp[j]
            if tmp_max > 0:
                dp[i] += tmp_max
            if dp[i] > ans:
                ans = dp[i]
        return ans
