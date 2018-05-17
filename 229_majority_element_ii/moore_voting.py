class Solution:
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        """
        Use two idx to store temp maxIdx1 maxIdx2.
        If one of the elements' occurrence is cancelled, assign new element.
        If the current element is not equal to maxIdx1, maxIdx2, subtract both 
        two elements' occurrences.

        Complexity: O(n)
        Space: O(1)
        """
        if nums == []:
            return []
        maxIdx1 = 0
        maxIdx2 = -1
        count1 = 1
        count2 = -1
        for i in range(1, len(nums)):
            # check if it is max1
            if nums[i] == nums[maxIdx1]:
                count1 += 1
            elif count2 > 0 and nums[i] == nums[maxIdx2] :
                # check if it is max2
                count2 += 1 
            # if the occurrence is cancelled 
            # Check at next loop, not right after the occurrence is subtracted
            # it would lead to problems when the input is [1,1,1,2,3,4,5,6]
            # when the max2 change to a new number, the max1 would be subtracted 
            # twice in this case.
            elif count1 < 1:
                maxIdx1 = i
                count1 = 1
            elif count2 < 1:
                maxIdx2 = i
                count2 = 1
            else:
                count1 -= 1
                count2 -= 1
                
        anslist = []
        occ1 = 0
        occ2 = 0
        for num in nums:
            if num == nums[maxIdx1]:
                occ1 += 1
            elif maxIdx2 > 0:
                if num == nums[maxIdx2]:
                    occ2 += 1
        if occ1 > (len(nums)//3):
            anslist.append(nums[maxIdx1])
        if occ2 > (len(nums)//3):
            anslist.append(nums[maxIdx2])
        return anslist
