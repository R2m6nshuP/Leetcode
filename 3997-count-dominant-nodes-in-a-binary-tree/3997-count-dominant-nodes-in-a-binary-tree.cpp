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
    int ans=0;
    int maxinsubtree(TreeNode* root){
        if(!root) return 0;
        int l=maxinsubtree(root->left);
        int r=maxinsubtree(root->right);
        if(root->val>=max(l,r)) {
            ans++;
            // cout<<root->val<<" ";
            return root->val;
        }
        else return max(l,r);
    }
    int countDominantNodes(TreeNode* root) {
        maxinsubtree(root);
        return ans;
    }
};