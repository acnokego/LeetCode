class Solution:
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        """
        Dynamic Programming
        Complexity: O(n)
        Space: O(n)
        """
        if len(nums) == 0:
            return 0
        elif len(nums) == 1:
            return nums[0]
        
        max_money = [0]*len(nums)
        # boundary condition
        max_money[0] = nums[0]
        max_money[1] = max(max_money[0], nums[1])

        for i in range(2, len(nums)):
            max_money[i] = max(max_money[i-1], nums[i] + max_money[i-2])
            
        return max_money[-1]
