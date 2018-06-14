class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        """
        Complexity: O(n)
        Space: O(1)
        Reverse the whole array first, then reverse the first k element (move 
        from the last few indexes of the array to its origin order) the the rest
        elements.
        """
        k = k % len(nums)
        def reversed(start, end, arr):
            length = end - start + 1
            middle = length // 2 
            for i in range(middle):
                tmp = arr[start + i]
                arr[start + i] = arr[end-i]
                arr[end-i] = tmp
        
        reversed(0, len(nums)-1, nums)
        reversed(0, k-1, nums)
        reversed(k, len(nums)-1, nums)
