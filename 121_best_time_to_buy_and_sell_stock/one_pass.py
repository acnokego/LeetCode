class Solution:
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """ 
        """
        Complexity: O(n)
        Space: O(1)
        """
        ans = 0
        min_val = float('inf')
        for i in range(len(prices)):
            if prices[i] < min_val:
                min_val = prices[i]
            if prices[i] - min_val > ans:
                ans = prices[i] - min_val
        return ans
