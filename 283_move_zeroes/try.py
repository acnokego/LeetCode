class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        """
        Complexity: O(n)
        Space: O(1)
        maintain the index of last zero, if there is nonzero value then swap
        it with the last zero, and move the index right for one pos. (the next 
        zero would be at the next position (either consecutive 0s or swap with the 
        next number) )
        """
        last_zero_idx = -1
        for i in range(len(nums)):
            if nums[i] == 0 and last_zero_idx < 0:
                last_zero_idx = i
            elif last_zero_idx >= 0 and nums[i] != 0:
                tmp = nums[i]
                nums[i] = 0
                nums[last_zero_idx] = tmp
                last_zero_idx += 1
            else:
                continue
                
