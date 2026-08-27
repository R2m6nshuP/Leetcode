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
    TreeNode* ans=NULL;
    bool parent(TreeNode* root,TreeNode* p){
        if(!root) return 0;
        if(root->val==p->val) return 1;
        return (parent(root->left,p) || parent(root->right,p));
    }
    void helper(TreeNode* root,TreeNode* p, TreeNode* q){
        if(!root) return;
        helper(root->left,p,q);
        if(ans) return;
        helper(root->right,p,q);
        if(ans) return;
        if(parent(root,q) && parent(root,p)) {
            if(!ans) ans=root;
            return;
        }
        

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==q) return p;
        helper(root,p,q);
        return ans;
    }
};