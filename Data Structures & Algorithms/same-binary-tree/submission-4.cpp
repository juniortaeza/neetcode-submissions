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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*, TreeNode*>> treeQ;
        treeQ.push({p, q});
        while(!treeQ.empty()){
            pair<TreeNode*, TreeNode*> treePair = treeQ.front(); treeQ.pop();
            TreeNode* x = treePair.first;
            TreeNode* y = treePair.second;

            if(!x && !y)
                continue;
                
            if(!x && y || x && !y)
                return false;
            if(x->val != y->val)
                return false;
            
            treeQ.push({x->left, y->left});
            treeQ.push({x->right, y->right});
        }
        return true;
    }
};
