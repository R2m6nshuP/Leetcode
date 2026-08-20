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
    void helper(vector<string> &ans,string poss,TreeNode* root){
        if(!root->left && !root->right) {
            ans.push_back(poss);
            return ;
        }
        if(root->left) helper(ans,poss+"->"+to_string(root->left->val),root->left);
        if(root->right) helper(ans,poss+"->"+to_string(root->right->val),root->right);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans;
        string poss=to_string(root->val);
        helper(ans,poss,root);
        return ans;
    }
};