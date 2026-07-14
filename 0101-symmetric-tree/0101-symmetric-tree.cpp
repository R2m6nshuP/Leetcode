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
    bool crossCheck(TreeNode* l,TreeNode* r){
        if(!l && !r) return 1;
        if(!l || !r) return 0;
        if(l->val != r->val) return 0;
        return crossCheck(l->left,r->right) && crossCheck(l->right,r->left); 
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return 1;
        return crossCheck(root->left,root->right);
    }
};