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
    //take information from ur subtree thats how you would know what to do
    int dfs(TreeNode* root){
        if(!root) return 2; //2 is code for covered
        int l=dfs(root->left);
        int r=dfs(root->right);
        if(l==0 || r==0) {
            ans++;
            return 1;
        }
        if(l==1 || r==1) return 2;
        return 0;
    }
    int minCameraCover(TreeNode* root) {
    if(!dfs(root)) ans++;
    return ans;    
    }
};