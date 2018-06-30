# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        """
        Complexity: O(max(d(l1), d(l2)) number of digits
        Space: O(max(d(l1), d(l2)))
        """
        carry = 0
        begin = ListNode(None)
        start = begin
        while l1 is not None or l2 is not None :
            if l1 is not None and l2 is not None:
                sum = l1.val + l2.val + carry
                l1 = l1.next
                l2 = l2.next
            elif l1 is not None: 
                sum = l1.val + carry
                l1 = l1.next
            else:
                sum = l2.val + carry 
                l2 = l2.next
            if sum >= 10:
                carry = 1
                sum = sum % 10
            else:
                carry = 0
            digit = ListNode(sum)
            begin.next = digit
            begin = digit
        if carry != 0:
            digit = ListNode(carry)
            begin.next = digit
        return start.next
    
                
