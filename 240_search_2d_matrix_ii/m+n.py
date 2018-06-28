class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        """
        Complexity: O(m+n)
        Space: O(1)
        Started from the top-right, if the target is smaller, move left (one col)
        else move down (one row)
        """
        if matrix == [] or matrix[0] == []:
            return False
        m = 0
        n = len(matrix[0]) - 1
        while(m < len(matrix) and n >= 0):
            if matrix[m][n] == target:
                return True
            if matrix[m][n] > target:
                n -= 1
            else:
                m += 1
                
        return False
