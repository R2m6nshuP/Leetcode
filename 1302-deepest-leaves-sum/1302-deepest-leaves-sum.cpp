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
    unordered_map<int,int> mp;
    void helper(TreeNode* root,int l) {
        if(!root) return;
        if(!root->left && !root->right) {
            mp[l]+=root->val;
            return;
        }
        helper(root->left,l+1);
        helper(root->right,l+1);
        }
    int deepestLeavesSum(TreeNode* root) {
        helper(root,0);
        int ans=0;
        int l=-1;
        for(auto &[le,su]: mp){
            if(le>l){
                l=le;
                ans=su;
            }
        }
        return ans;
    }
};