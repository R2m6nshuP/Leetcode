class Solution {
public:
    string largestOddNumber(string num) {
        int end=-1;
        int i=num.size()-1;
        while(i>=0){
            if(int(num[i])%2==1){
                end=i;
                break;
            }
            --i;
        }
        string ans= (end==-1) ? ""  : num.substr(0,end+1);
        return ans;
    }
};