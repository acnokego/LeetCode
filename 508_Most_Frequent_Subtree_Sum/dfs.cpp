/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    /*
     * Complexity: O(n)
     * Space: O(n) // space for the unordered_map
     */
    int getTreeSum(TreeNode* root, unordered_map<int,int>& occur, int& maxCount) {
        if(!root) return 0;
        int left_sum = getTreeSum(root -> left, occur, maxCount);
        int right_sum = getTreeSum(root -> right, occur, maxCount);
        int sum = root -> val + left_sum + right_sum;
        occur[sum] += 1;
        maxCount = (occur[sum] > maxCount) ? occur[sum] : maxCount;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int>ans;
        if(!root) return ans;
        int maxCount = 0;
        unordered_map<int, int>sum_occur;
        getTreeSum(root, sum_occur, maxCount);

        for(auto it = sum_occur.begin(); it != sum_occur.end(); ++it){
            if(it -> second == maxCount){
                ans.push_back(it -> first);
            }
        }
        return ans;
        
        
    }
};
