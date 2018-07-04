class Solution:
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        """
        Complexity: O(n)
        Space: O(1)
        Keep moving the current position one step at a time and updating the 
        maximum index we can reach now. If we can move to the last index then 
        return True, otherwise our current position is larger than max reach, 
        then return False.
        """
        if nums == []: 
            return False
        max_reach = 0
        pos = 0
        for pos in range(len(nums)):
            if pos > max_reach:
                return False
            max_reach = max(max_reach, nums[pos] + pos)
            pos += 1
        return True
