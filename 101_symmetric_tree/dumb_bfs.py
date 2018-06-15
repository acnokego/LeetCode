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
        For each layer, see if it is symmetric, using bfs traverse.
        """
        def islayerSymmetric(arr):
            middle = len(arr) // 2
            ans = [arr[i] == arr[-1-i] for i in range(middle)]
            return (sum(ans) == middle)
        if root == None:
            return True
        import queue
        bfs = queue.Queue()
        bfs.put(root)
        last_layer_num = 1
        layer_arr = []
        while not bfs.empty():
            node = bfs.get()
            if node.left is not None:
                bfs.put(node.left)
                layer_arr.append(node.left.val)
            else:
                layer_arr.append('null')
            if node.right is not None:
                bfs.put(node.right)
                layer_arr.append(node.right.val)
            else:
                layer_arr.append('null')
            if len(layer_arr) == 2*last_layer_num:
                if not islayerSymmetric(layer_arr):
                    return False
                last_layer_num = len(layer_arr) - layer_arr.count('null')
                layer_arr = []
        return True
