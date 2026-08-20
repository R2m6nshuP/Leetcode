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
    void helper(vector<vector<int>> &ans,vector<int> poss,TreeNode* root,int targetSum){
        if(!root) return;
        targetSum-=root->val;
        poss.push_back(root->val);
        if(!root->left && !root->right){
            if(0==targetSum) ans.push_back(poss);
            return;
        }
        helper(ans,poss,root->left,targetSum);
        helper(ans,poss,root->right,targetSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;
        vector<int> poss;
        helper(ans,poss,root,targetSum);
        return ans;
    }
};