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
    map<pair<int,int>,vector<TreeNode*>> mp;
    vector<TreeNode*> solve(int start,int end){
        auto it=mp.find({start,end});
        if(it!=mp.end()) return it->second;
        vector<TreeNode*> ans;
        if(start>end) {
            return ans;
        }
        if(start==end) {
            auto newadd=new TreeNode(start);
            ans.push_back(newadd);
            return mp[{start,end}]=ans;
        }
        for(int i=start;i<=end;i++){
            
            auto leftbst=solve(start,i-1);
            auto rightbst=solve(i+1,end);
            if(!leftbst.empty() && !rightbst.empty()) {
            for(auto l : leftbst){
                for(auto r: rightbst){
                    auto root=new TreeNode(i);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
            }
            else if(leftbst.empty() && !rightbst.empty()){
                for(auto r: rightbst){
                    auto root=new TreeNode(i);
                    root->right=r;
                    ans.push_back(root);
                }
            }
            else if(rightbst.empty()  && !leftbst.empty()){
                for(auto l: leftbst){
                    auto root=new TreeNode(i);
                    root->left=l;
                    ans.push_back(root);
                }
            }
        }
        return mp[{start,end}]=ans;
    }
    vector<TreeNode*> generateTrees(int n) {
       return solve(1,n);  
    }
};