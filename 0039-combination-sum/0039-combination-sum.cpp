class Solution {
public:

    void insert(vector<vector<int>> &ans,vector<int>& candidates,int target,vector<int> &poss,int i){ 
        if(target==0) { ans.push_back(poss);
        return;
        }
        if(target<0) return;
        if(i==candidates.size()) return ;
        insert(ans,candidates,target,poss,i+1);
        if(candidates[i]<=target)
        {poss.push_back(candidates[i]);
        insert(ans,candidates,target-candidates[i],poss,i);
        poss.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> poss;
    insert(ans,candidates,target,poss,0);
    return ans;
    }
};