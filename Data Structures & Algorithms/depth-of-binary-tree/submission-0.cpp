/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int levels = 0;

        while(!q.empty()){
            int levelSize = q.size();
            levels += 1;
            for(int i = 0; i < levelSize; i++){
                TreeNode* n = q.front(); q.pop();
                if(n->left)  q.push(n->left);
                if(n->right) q.push(n->right);
            }
        }

        return levels;
    }
};
