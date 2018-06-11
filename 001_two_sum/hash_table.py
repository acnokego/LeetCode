class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        """
        Using dict to record idx for each element. Iterate throgh the array and
        search its complement throgh hash O(1) (amotized, worst would be O(n)).

        Complexity: O(n)
        SpaceL O(n)
        """
        idx_dict = {}
        for idx, ele in enumerate(nums):
            if ele in idx_dict: # it's O(1) if you called keys() then it's O(n)
                idx_dict[ele].append(idx)
            else:
                idx_dict[ele] = [idx]
                
        for idx in range(len(nums)): #O(n)
            complement = target - nums[idx]
            if complement in idx_dict:
                if nums[idx] is not complement:
                    return[idx, idx_dict[complement][0]]
                elif len(idx_dict[complement]) == 2:
                    return[idx, idx_dict[complement][1]]
