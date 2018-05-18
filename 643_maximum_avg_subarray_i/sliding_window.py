class Solution:
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        """
        Complexity: O(n)
        Space: O(1)
        """
        tpsum = sum(nums[0:k])
        maxsum = tpsum
        for i in range(1, len(nums)-k + 1):
            # if directly compute the sum of each posibilities of subarrays
            # the complexity becomes O(n*k)
            # it would lead to huge computation time when k ~ n
            tpsum = tpsum - nums[i-1] + nums[i+k-1]
            if tpsum > maxsum:
                maxsum = tpsum
        return (1.0 * maxsum) / k
