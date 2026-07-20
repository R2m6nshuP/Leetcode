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
    TreeNode* helper(TreeNode* &temp){
        if(!temp->left) return temp->right;
        else if(!temp->right) return temp->left;
        else{
            TreeNode* lastRight=temp->left;
            while(lastRight->right) lastRight=lastRight->right;
            lastRight->right=temp->right;
            return temp->left;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        TreeNode* temp=root;
        if(temp->val==key) root=helper(temp);

        while(temp){
            if(temp->val>key ){
                if(temp->left && temp->left->val==key){
                    temp->left=helper(temp->left);
                    break;
                }
                else temp=temp->left;
            }
            else{
                if(temp->right && temp->right->val==key){
                    temp->right=helper(temp->right);
                    break;
                }
                else temp=temp->right;
            }
        } 
        return root;
    }
};