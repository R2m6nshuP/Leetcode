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
    pair<int,int> ans={0,-1};
    void helper(TreeNode* root,int l) {
        if(!root) return;
        if(!root->left && !root->right) {
            if(l>ans.second) ans={root->val,l};
            else if(l==ans.second) ans={ans.first+root->val,l};
            return;
        }
        helper(root->left,l+1);
        helper(root->right,l+1);
        }
    int deepestLeavesSum(TreeNode* root) {
        helper(root,0);
        return ans.first;
    }
};