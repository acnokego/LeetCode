class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        """
        too slow...
        Complexity: O(n^2)
        Space: O(n^2) or O(1) if just use double loops
        """
        from itertools import combinations
        combs = combinations(range(len(nums)), 2)
        for comb in combs:
            if nums[comb[0]] + nums[comb[1]] == target:
                return [comb[0], comb[1]]
            
