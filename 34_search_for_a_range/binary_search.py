class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        """
        Complexity: O(logn)
        Space: O(1)
        """
        
        def searchRange_sub(nums, start, end, target):
            if start == end:
                if nums[start] is not target:
                    return [-1,-1]
                else:
                    return [start, end]
            elif start > end:
                return [-1, -1]
            mid = nums[(end+start) // 2] 
            if mid > target:
                return searchRange_sub(nums, start, (end+start)//2 - 1,  target)
            elif mid < target:
                return searchRange_sub(nums, (end+start)//2 + 1, end, target)
            else:
                left = searchRange_sub(nums, start, (end+start)//2 - 1, target)
                right = searchRange_sub(nums, (end+start)//2 + 1, end, target)
                ans = []
                if left[0] is not -1 :
                    ans.append(left[0])
                else:
                    ans.append((end+start)//2)
                if right[1] is not -1 :
                    ans.append(right[1])
                else:
                    ans.append((end+start)//2)
                return ans
        
        n = len(nums)
        return searchRange_sub(nums, 0, n-1, target)
