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
    void helper(vector<vector<int>> &ans,TreeNode* temp,int level){
        if(!temp) return ;
        if(level==ans.size()) ans.push_back({});
        ans[level].push_back(temp->val);
        helper(ans,temp->left,level+1);
        helper(ans,temp->right,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper(ans,root,0);
        return ans;
    }
};