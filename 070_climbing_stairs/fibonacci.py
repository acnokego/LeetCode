class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        """
        Complexity: O(n)
        Space: O(1)
        """
        if n >= 1:
            first = 1
            if n >= 2:
                second = 2
            else:
                return 1
        else:
            return 0
        for i in range(3, n+1):
            third = first + second
            first = second
            second = third
        return second
