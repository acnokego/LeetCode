class Solution:
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        """
        This method only worked in Python, since integers in Python has 
        arbitrary precision.
        -> http://mortada.net/can-integer-operations-overflow-in-python.html
        """
        num_R = m-1 
        num_D = n-1
        return int(math.factorial(num_R + num_D) / (math.factorial(num_R)*math.factorial(num_D)))
