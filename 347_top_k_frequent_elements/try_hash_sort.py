class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        """
        Complexity: O(nlgn)
        Space: O(n)
        """
        if nums == []:
            return []
        occur = {}
        for n in nums:
            if n not in occur:
                occur[n] = 1
            else:
                occur[n] += 1
        sorted_occur = sorted(occur.items(), key=lambda x : x[1], reverse=True)
        ans = [sorted_occur[i][0] for i in range(k)]
        return ans
