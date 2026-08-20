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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int ans=INT_MAX;
        if(root->left) ans=min(ans,minDepth(root->left)+1);
        if(root->right) ans=min(ans,minDepth(root->right)+1);
        if(ans==INT_MAX) return 1;
        else return ans;
    }
};