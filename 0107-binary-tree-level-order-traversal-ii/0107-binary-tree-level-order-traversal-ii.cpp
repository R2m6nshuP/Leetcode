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
    void helper(vector<vector<int>> &ans,TreeNode* root,int level){
        if(!root) return;
        if(ans.size()==level) ans.push_back({});
        ans[level].push_back(root->val);
        helper(ans,root->left,level+1);
        helper(ans,root->right,level+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        helper(ans,root,0);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};