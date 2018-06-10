class Solution:
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        """
        Complexity : O(n^2)
        Space: O(n)
        """
        # one additional space for base condition
        # isbreak[i] indicates that s[0:i] is breakable
        isbreak = [False]*(len(s) + 1)
        isbreak[0] = True
        for i in range(len(s)):
            # for each char
            # check if the previous string could be separate into s[0:j],
            # and s[j:i+1] 
            for j in range(i, -1, -1): 
                if isbreak[j] and s[j : i+1] in wordDict:
                    isbreak[i+1] = True
                    break
 
        return isbreak[-1]
