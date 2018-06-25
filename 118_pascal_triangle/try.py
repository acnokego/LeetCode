class Solution:
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        """
        Complexity: O(numRows^2), 1+2+3+...+numRows
        Space: O(numRows^2)
        """
        ans = []
        for i in range(numRows):
            if i == 0:
                ans.append([1])
                continue
            row = [1 if j == 0 or j == i else ans[i-1][j-1] + ans[i-1][j] for j in range(i+1)]
            ans.append(row)
        return ans
