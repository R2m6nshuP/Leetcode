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
    void helper(TreeNode* left,TreeNode* right,int l){
        if(!left) return ;
        helper(left->left,right->right,l+1);
        helper(left->right,right->left,l+1);
        if(l%2==1) {
            swap(left->val,right->val);
        }
    }
    TreeNode* reverseOddLevels(TreeNode* root) {
        helper(root->left,root->right,1);
        return root;
    }
};