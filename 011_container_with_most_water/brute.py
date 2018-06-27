class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        """
        Complexity: O(n^2) not work
        Space: O(1)
        """
        ans = 0
        for i in range(len(height)):
            for j in range(i):
                ans = (i-j)*min(height[i],height[j]) if (i-j)*min(height[i],height[j]) > ans else ans
        return ans
        
