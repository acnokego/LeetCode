class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        """
        Complexity: O(n)
        Space: O(n)
        """
        order = []
        pair = {'}':'{', ']':'[', ')':'('}
        for id, c in enumerate(s):
            if c in pair.values():
                order.append(c)
            elif c in pair:
                if not len(order) or pair[c] is not order.pop():
                    return False
            else:
                return False
        return order == []
                
    
