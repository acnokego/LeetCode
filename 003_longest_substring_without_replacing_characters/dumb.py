class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = []
        tmp_long_str = []
        for c in s:
            if tmp_long_str == []:
                tmp_long_str.append(c)
            elif c not in tmp_long_str:
                tmp_long_str.append(c)
            
            # if repeat
            else:
                ind = tmp_long_str.index(c) # the last occurrence
                if len(tmp_long_str) > len(ans):
                    ans = tmp_long_str[:]
                tmp_long_str = tmp_long_str[ind+1:] + [c] # from the last occurrence to this char
                
        # if the longest is in the end 
        if len(tmp_long_str) > len(ans):
            ans = tmp_long_str[:]
        return len(ans)
