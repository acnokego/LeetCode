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
        ## calculate the sum first
        digit = 1
        sum_num = 0
        while l1 is not None or l2 is not None:
            if l1 is not None and l2 is not None:
                sum_num += digit*(l1.val + l2.val)
                l1 = l1.next
                l2 = l2.next
            elif l1 is not None: 
                sum_num += digit*(l1.val)
                l1 = l1.next
            else:
                sum_num += digit*(l2.val) 
                l2 = l2.next
            digit *= 10
        divide = 10
        ans = ListNode(0)
        if sum_num == 0:
            return ans
        start = ans
        # find the digit from the rightmost digit
        while sum_num /divide >= 0.1:
            digit = ListNode(int((sum_num % divide) // (divide / 10)))
            print(digit.val)
            ans.next = digit
            ans = digit
            divide *= 10
            
        return start.next
                
