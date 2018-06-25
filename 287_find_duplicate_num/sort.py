class Solution:
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        """
        Complexity: O(nlgn) quick sort avg case
        Space: O(1)
        """
        if nums == []:
            return -1
        sort_nums = sorted(nums)
        last_element = 0
        for ele in sort_nums:
            if ele == last_element:
                return ele
            else:
                last_element = ele
