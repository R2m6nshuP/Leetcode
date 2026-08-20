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
    void helper(unordered_set<int> &mp,int &prevcnt,int &cnt,int &prev,TreeNode* root){
        if(!root) return;
        helper(mp,prevcnt,cnt,prev,root->left);
        if(prev==root->val) {
            cnt++;
        }
        else{
            if(cnt>prevcnt){
                mp.clear();
                mp.insert(prev);
                prevcnt=cnt;
            }
            else if(cnt==prevcnt){
                mp.insert(prev);
            }
            cnt=1;
            prev=root->val;
        } 
        
        helper(mp,prevcnt,cnt,prev,root->right);
    }
    vector<int> findMode(TreeNode* root) {
        int prevcnt=-1;
        int cnt=0;
        int prev=INT_MIN;
        unordered_set<int> mp;
        helper(mp,prevcnt,cnt,prev,root);
        if(cnt>prevcnt){
                mp.clear();
                mp.insert(prev);
            }
        else if(cnt==prevcnt){
                mp.insert(prev);
            }
        vector<int> ans(mp.begin(),mp.end());
        return ans;
    }
};