class Solution:
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        """
        Complexity: O(n)
        Space: O(1)
        The first pointer indicates the pos of last non zero element (from head).
        The second pointer indicates the pos of first non two element (from tail).
        """
        last_non_zero_idx = 0
        first_non_two_idx = len(nums) - 1
        for i in range(len(nums)):
            if i > first_non_two_idx:
                return
            if nums[i] == 0:
                # since we intialize non_zero in a naive way, this condition is needed
                if nums[last_non_zero_idx] != 0:
                    #swap with zero_idx
                    tmp = nums[last_non_zero_idx]
                    nums[last_non_zero_idx] = 0
                    nums[i] = tmp
                    last_non_zero_idx += 1
                # the first few elements are zeros
                else:
                    last_non_zero_idx += 1
            if nums[i] == 2:
                # since we initialize non_two in a naive way, the loop help us find first non_two
                while first_non_two_idx > i:
                    if nums[first_non_two_idx] != 2:
                        # swap with two_idx
                        tmp = nums[first_non_two_idx]
                        nums[first_non_two_idx] = 2
                        nums[i] = tmp
                        first_non_two_idx -= 1
                        # if the non_two we swap is 0, it needed to be swapped with the non_zero again
                        if nums[i] == 0:
                            if last_non_zero_idx < i: 
                                tmp = nums[last_non_zero_idx]
                                nums[last_non_zero_idx] = 0
                                nums[i] = tmp
                                last_non_zero_idx += 1
                            else:
                                last_non_zero_idx += 1
                        break
                    else:
                        first_non_two_idx -= 1
                    # if we cannot find non_two, which means from i to end is all 2    
                    if first_non_two_idx == i:
                        return
