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
    void helper(vector<int> &ans,TreeNode* root,int l){
        if(!root) return ;
        if(l==ans.size()) ans.push_back(root->val);
        helper(ans,root->right,l+1);
        helper(ans,root->left,l+1);
    }
    vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    helper(ans,root,0);
    return ans;
    }
};