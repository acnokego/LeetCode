/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
 * Complexity: O(n) still need to traverse the whole array
 * Space: O(lgn)
 */
class Solution {
public:
    // return the root
    TreeNode* binary_traverse(vector<int>& nums, int start, int end){
        // if there are only two elements in last stack, the start would > end.
        if(start > end) return NULL;
        int size = end - start + 1;
        int mid = size / 2;
        TreeNode* root = new TreeNode(nums[start + mid]);
        // when start == end
        if(size == 1) return root;
        root -> left = binary_traverse(nums, start, start + mid - 1);
        root -> right = binary_traverse(nums, start + mid + 1, end);
        return root;        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return NULL;
        return binary_traverse(nums, 0, size-1);
    }
};
