class Solution:
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        """
        - Complexity: O(amount*len(coins))
        - Space: O(amount)
        - Dynamic Programming, let dp[i] be the fewest coins needed when the amount
        is i.
        - Notice that there is no greedy property (select the largest coin first)
        """
        MAX = float('inf')
        dp = [-1]*(amount+1)
        dp[0] = 0
        for i in range(1, amount+1):
            """
            original implementation:
            for j in range(len(coins)):
                if i >= coins[j] and dp[i-coins[j]] >= 0:
                    dp[i] = 1 + dp[i-coins[j]] if dp[i] < 0 else min(dp[i], 1+dp[i-coins[j]])
                else:
                    continue
            Time Limited Exceed, for loop too slow
            """
            dp[i] = min([1 + dp[i-coins[j]] if i >= coins[j] else MAX for j in range(len(coins))])
        return -1 if dp[-1] == MAX else dp[-1]
