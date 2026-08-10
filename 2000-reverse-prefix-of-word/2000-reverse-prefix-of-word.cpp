class Solution {
public:
    string reversePrefix(string word, char ch) {
        bool found=0;
        int i=-1;
        for(i=0;i<word.size();i++){
            if(word[i]==ch){
                found=1;
                break;
            }
        }
        if(found) reverse(word.begin(),word.begin()+i+1);
        return word;
    }
};