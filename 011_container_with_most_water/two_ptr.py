class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        """
        Complexity: O(n)
        Space: O(1)
        Explore from the two most exterior lines (the longest width), then move
        the shorter line inward to see if we could get longer line.
        """
        ans = 0
        left = 0 
        right = len(height) - 1
        while left != right :
            if height[left] > height[right]:
                ans = (right-left)*height[right] if (right-left)*height[right] > ans else ans
                right -= 1
            else:
                ans = (right-left)*height[left] if (right-left)*height[left] > ans else ans
                left += 1
        return ans
