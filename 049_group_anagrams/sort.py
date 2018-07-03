class Solution:
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        """
        Complexity: O(nklgk), n: length of strs, k: max length of str
        Space: O(nk)
        """
        ans = collections.defaultdict(list)
        for str in strs:
            ans[tuple(sorted(str))].append(str)
        return list(ans.values())
