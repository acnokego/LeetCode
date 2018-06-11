# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        """
        Complexity: O(n) one pass.
        Space: O(1) two ptrs.
        """
        # two pointers
        # ptr start from n element after the origal pos
        # new ptr start from n element and would point to the element before the removed element.
        ptr = head
        new_ptr = head
        # move ptr to be n element after the new_head
        # 1->2->3....-> n+1 (ptr) 
        # remove 2 if n+1 is the end
        for i in range(n):
            ptr = ptr.next
            if ptr is None: # if we need to remove the first one
                return head.next
            
        while head is not None:
            if ptr.next is not None:
                # ptr: 1->2->3...->n+1
                # new_ptr: 1 
                # if ptr.next, new_ptr: 1->2, 
                new_ptr = new_ptr.next
                ptr = ptr.next  
            else: 
                # if ptr: 1->2->3...->last element
                # new ptr: 1->2->3...->element before the removed one, new_ptr->next is on the removed one
                new_ptr.next = new_ptr.next.next 
                break

        return head
