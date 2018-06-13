class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        """
        Complexity: O(n)
        Space: O(n)
        use hash to store used char
        """
        max_length = 0
        start = 0
        used_char = {}
        for i, c in enumerate(s):
            if c in used_char and start <= used_char[c]:
                start = used_char[c] + 1 # start from the next char of the last occurrence
            else:
                max_length = max(max_length, i-start+1)
            used_char[c] = i
                
        return max_length
