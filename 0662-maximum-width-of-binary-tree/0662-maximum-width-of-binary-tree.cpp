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
    unsigned long long ans=0;
    vector<unsigned long long> first;
    void helper(TreeNode* root,int level,unsigned long long index){
        if(!root) return;
        if(level==first.size()) first.push_back(index);
        ans=max(ans,1+index-first[level]);
        helper(root->left,level+1,2*index);
        helper(root->right,level+1,2*index+1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        helper(root,0,1);
        return ans;
    }
};