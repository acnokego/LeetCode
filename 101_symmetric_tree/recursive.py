# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        """
        Complexity: O(n)
        Space: O(n)
        """
        if root == None:
            return True
        def sub_isSymmetric(right, left):
            if right == None and left == None:
                return True
            if right == None or left == None:
                return False
            if right.val == left.val and sub_isSymmetric(right.right, left.left) and sub_isSymmetric(right.left, left.right):
                return True
            else:
                return False
        return sub_isSymmetric(root.right, root.left)
