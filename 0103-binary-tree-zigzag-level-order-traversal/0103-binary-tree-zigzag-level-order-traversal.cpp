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
void helper0(vector<vector<int>> &ans,TreeNode* temp,int level){
        if(!temp) return ;
        if(level==ans.size()) ans.push_back({});
        if(level%2==0) {
        ans[level].push_back(temp->val);
        }
        helper0(ans,temp->left,level+1);
        helper0(ans,temp->right,level+1);          
        }
    void helper1(vector<vector<int>> &ans,TreeNode* temp,int level){
        if(!temp) return ;
        if(level==ans.size()) ans.push_back({});
        if(level%2==1) {
        ans[level].push_back(temp->val);
        }
        helper1(ans,temp->right,level+1); 
        helper1(ans,temp->left,level+1);
                  
        }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        helper1(ans,root,0);
        helper0(ans,root,0);

        return ans;
    }
};