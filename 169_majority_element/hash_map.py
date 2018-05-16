class Solution:
    def majorityElement(self, nums):
        """
        Use an HashMap to store the occurrence of each element and find the one
        with the max occurrence.

        Complexity: O(n) (Iterate through the whole array)
        Space: O(n)
        """
        counts = collections.Counter(nums)
        # counts.get is a method that could retrive the occurrence with element 
        # as input argument.
        return max(counts.keys(), key=counts.get)
