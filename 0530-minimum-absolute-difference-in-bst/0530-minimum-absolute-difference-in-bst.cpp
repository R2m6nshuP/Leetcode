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
    void helper(int &ans,TreeNode* root){
        if(!root) return;
        TreeNode* temp=root;
        if(root->left) {
            temp=root->left;
            while(temp->right) temp=temp->right;
            ans=min(ans,abs(root->val-temp->val));
            helper(ans,root->left);
        }
        if(root->right) {
            temp=root->right;
            while(temp->left) temp=temp->left;
            ans=min(ans,abs(root->val-temp->val));
            helper(ans,root->right);
        }
    }
    int getMinimumDifference(TreeNode* root) {
        int ans=INT_MAX;
        helper(ans,root);
        return ans;
    }
};