class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        """
        Complexity: O(n)
        Space: O(n)
        need not save the index... 
        apply the feature of stack...
        """
        order = {'{': [-1], '[':[-1], '(':[-1]}
        for id, c in enumerate(s):
            if c == '{' or c == '[' or c == '(':
                order[c].append(id)
                
            elif c == '}':
                if len(order['{']) and order['{'][-1] is not -1 and max(enumerate([order['{'][-1], order['['][-1] , order['('][-1]]), key=lambda p:p[1])[0] == 0:
                    order['{'].pop()
                else:
                    return False
            elif c == ']':
                if len(order['[']) and order['['][-1] is not -1 and max(enumerate([order['{'][-1], order['['][-1] , order['('][-1]]), key=lambda p:p[1])[0] == 1:
                    order['['].pop()
                else:
                    return False
            elif c == ')':
                if len(order['(']) and order['('][-1] is not -1 and max(enumerate([order['{'][-1], order['['][-1] , order['('][-1]]), key=lambda p:p[1])[0] == 2:
                    order['('].pop()
                else:
                    return False

        for p in order:
            if len(order[p]) > 1:
                return False
        else: 
            return True
