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
    void helper( int &val,TreeNode* &curr) {
        if(val>curr->val) {
            if(!curr->right){
                TreeNode* formed = new TreeNode(val);
                curr->right=formed;
                return ;
            }
            else helper(val,curr->right);
        }
        else {
            if(!curr->left){
                TreeNode* formed= new TreeNode(val);
                curr->left=formed;
                return ;
            }
            else helper(val,curr->left);
        }
        return ;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(!root) {
            root=new TreeNode(val);
            return root;
        }
        helper(val,root);
        return root;
    }
};