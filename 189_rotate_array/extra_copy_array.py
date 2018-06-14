class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        """
        Complexity: O(n)
        Space: O(n)
        Created one extra copy of original list, and used it for the assignment 
        of the rotating list.
        """
        ori_nums = nums[:]
        
        # need to mod len in case the k is biggen than len(nums)
        for idx in range(len(nums)):
            nums[idx] = ori_nums[idx-(k % len(nums))]
