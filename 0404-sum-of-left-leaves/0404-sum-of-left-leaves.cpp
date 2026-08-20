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
    void helper(int &ans,TreeNode* root,int level){
        if(!root->left && !root->right && (level%2 == 0)){
            ans+=root->val;
            return;
        }
        if(root->left) helper(ans,root->left,0);
        if(root->right) helper(ans,root->right,1);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        if(!root->left && !root->right) return ans;
        helper(ans,root,1);
        return ans;
    }
};