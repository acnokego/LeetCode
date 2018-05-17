class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        maxIdx = 0
        count = 1
        # Moore's voting alg.
        """
        It's like we would cancel out each occurrence of an element e with all
        the other element different from e so that it would exist till the end. 

        Complexity: O(n)
        Auxiliary Space: O(1)
        """
        for i in range(1, len(nums)):
            if nums[i] == nums[maxIdx]:
                count += 1
            elif count == 0:
                maxIdx = i
                count = 1
            else:
                count -= 1

        # verify the majority element we found
        occurrence = 0
        for num in nums:
            if num == nums[maxIdx]:
                occurrence += 1
        if occurrence > (len(nums) // 2):
            return nums[maxIdx]
        else:
            return 0
