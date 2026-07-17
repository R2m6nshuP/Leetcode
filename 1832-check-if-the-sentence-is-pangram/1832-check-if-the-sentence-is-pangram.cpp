class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> fq(26,0);
        for(int i=0;i<sentence.size();i++){
            fq[sentence[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(!fq[i]) return 0;
        }
        return 1;
    }
};