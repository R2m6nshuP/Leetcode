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
    void helper(TreeNode* root,long long &prev,bool &ans){
        if(!root) return;
        helper(root->left,prev,ans);
        if(!ans) return;
        if(root->val<=prev){
            ans=0;
            return;
        }
        prev=root->val;
        helper(root->right,prev,ans);
    }
    bool isValidBST(TreeNode* root) {
        long long prev = (long long)INT_MIN - 1;
        bool ans=1;
        helper(root,prev,ans);
        return ans;
    }
};