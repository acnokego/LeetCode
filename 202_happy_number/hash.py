class Solution:
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        """
        Space: O(n)
        """
        occur = {}
        while n not in occur:
            occur[n] = 1
            digit = 10
            sum = 0 
            while n >= 1:
                sum += (n % digit)**2
                n = n // digit
            if sum == 1:
                return True
            n = sum
        return False
