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
    pair<int,int> p(TreeNode* root,int n){
        if(!root) return {0,0};
        int ans=0;
        auto p1=p(root->left,n);
        auto p2=p(root->right,n);
        ans+=p1.first+p2.first;
        int l=p1.second;
        int r=p2.second;
        n+=root->val+l+r;
        return {abs(l-r)+ans,n};
    }
    int findTilt(TreeNode* root) {
        return p(root,0).first;
    }
};