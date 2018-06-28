class Solution:
    def searchMatrix(self, matrix, target):
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        """
        Complexity: O(mlgn)
        Space: O(1)
        """
        def binary_search(row, start, end, t):
            # can modify it with a while loop instead of recursion
            mid = (end- start + 1)//2
            if row[start + mid] == t:
                return True
            elif start == end:
                return False
            elif row[start + mid] > t:
                return binary_search(row, start, start+mid-1, t)
            else:
                return binary_search(row, start+mid, end, t)
            
        if matrix == [] or matrix[0] == []:
            return False
        m = len(matrix)
        n = len(matrix[0])
        for i in range(m):
            if target >= matrix[i][0] and target <= matrix[i][-1]:
                if binary_search(matrix[i], 0, n-1, target):
                    return True
            else:
                continue
        return False
