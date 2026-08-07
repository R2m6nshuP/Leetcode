class Solution {
public:
    int minOperations(vector<string>& logs) {
        int level=0;
        for(auto i : logs){
            if(i[0]!='.') {
                level+=1;
            }
            else if(i[1]=='.') {
                level--;
                if(level<0) level=0;
            }
        }
        if(level<=0) return 0;
        return level;
    }
};