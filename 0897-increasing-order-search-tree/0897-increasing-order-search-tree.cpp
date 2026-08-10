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
    TreeNode* increasingBST(TreeNode* root) {
        if(!root) return root;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* dumpy=new TreeNode(-1);
        TreeNode* tail=dumpy;
        while(!st.empty()){
            TreeNode* curr=st.top();
            st.pop();
            if(!curr->left && !curr->right){
                tail->right=curr;
                tail=tail->right;
            }
            else{
                if(curr->right) st.push(curr->right);
                st.push(curr);
                if(curr->left) st.push(curr->left);
                curr->left=NULL;
                curr->right=NULL;
            }
            
        }
        return dumpy->right;
    }
};