class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int s=0;s<words.size();s++){
            for(auto &i: words[s]){
                if(i==x){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};