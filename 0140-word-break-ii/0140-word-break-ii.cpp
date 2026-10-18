class Solution {
public:
    vector<string> ans;
    void helper(string s,unordered_set<string> &word,vector<string> &poss){
        if(s==""){
            string temp="";
            for(int i=0;i<poss.size();i++){
                if(i>0) temp+=" ";
                temp+=poss[i];
            }
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<s.size();i++){
            if(word.count(s.substr(0,i+1))){
                poss.push_back(s.substr(0,i+1));
                helper(s.substr(i+1),word,poss);
                poss.pop_back();
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word(wordDict.begin(),wordDict.end());
        vector<string> poss;
        helper(s,word,poss);
        return ans;
    }
};