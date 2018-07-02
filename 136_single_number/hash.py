class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        """
        Complexity: O(n)
        Space: O(n)
        """
        occur = {}
        for i in range(len(nums)):
            if nums[i] not in occur:
                occur[nums[i]] = 1
            else:
                occur[nums[i]] += 1
        for k in occur:
            if occur[k] == 1:
                return k
        return 0
