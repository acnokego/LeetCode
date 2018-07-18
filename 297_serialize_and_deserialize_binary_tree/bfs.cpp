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
 * Complexity: O(n)
 * Space: O(n)
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if(!root) return ans;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node == NULL){
                ans += "null,";
                q.pop();
                continue;
            }
            char val[33];
            sprintf(val, "%d", node -> val);
            ans += val;
            ans += ',';
            q.pop();
            q.push(node -> left);
            q.push(node -> right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        char* data_cpy = new char[data.length() + 1];
        strcpy(data_cpy, data.c_str());
        const char* tok = strtok(data_cpy, ",");
        if(tok == NULL || strcmp(tok, "null") == 0) return NULL;
        TreeNode* root = new TreeNode(atoi(tok));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            const char* left = strtok(NULL, ",");
            // end of the serialized data
            if(left == NULL){
                while(!q.empty()) q.pop();
                break;
            }
            // not null
            if(strcmp(left, "null") != 0){
                TreeNode* l = new TreeNode(atoi(left));
                tmp -> left = l;
                q.push(l);
            }
            const char* right = strtok(NULL, ",");
            // end of the serialized data
            if(right == NULL){
                while(!q.empty()) q.pop();
                break;
            }
                // not null
            if(strcmp(right, "null") != 0){
                TreeNode* r = new TreeNode(atoi(right));
                tmp -> right = r;
                q.push(r);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
