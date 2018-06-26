class Solution:
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        """
        Complexity: O(n)
        Space: O(n)
        """
        ans = [0]*(n+1)
        if n >= 1:
            ans[1] += 1
            if n >= 2:
                ans[2] += 2
            else:
                return 1
        else:
            return 0
        for i in range(3, n+1):
            ans[i] += (ans[i-1] + ans[i-2])
        return ans[-1]

