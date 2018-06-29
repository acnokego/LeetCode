class Solution:
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        """
        Complexity: O(n)
        Space: O(1) the table size stay constant no matter how large the n is
        """
        occurrence = {}
        for c in s:
            if c in occurrence:
                occurrence[c] += 1
            else:
                occurrence[c] = 1
        for c in t:
            if c in occurrence:
                occurrence[c] -= 1
            else:
                return False
        for c in occurrence.values():
            if c != 0:
                return False
        return True
