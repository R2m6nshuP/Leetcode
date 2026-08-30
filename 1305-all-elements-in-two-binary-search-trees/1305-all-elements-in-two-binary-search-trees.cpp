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
    void helper(vector<int> &v,TreeNode* root){
        if(!root) return;
        helper(v,root->left);
        v.push_back(root->val);
        helper(v,root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2,ans;
        helper(v1,root1);
        helper(v2,root2);
        int i=0;
        int j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<v2[j]) {
                ans.push_back(v1[i]);
                i++;
            }
            else if(v1[i]>v2[j]) {
                ans.push_back(v2[j]);
                j++;
            }
            else {
                ans.push_back(v1[i]);
                ans.push_back(v1[i]);
                i++;
                j++;
            }
        }
        while(i<v1.size()) {
            ans.push_back(v1[i]);
            i++;
        }
        while(j<v2.size()) {
            ans.push_back(v2[j]);
            j++;
        }
        return ans;
    }
};