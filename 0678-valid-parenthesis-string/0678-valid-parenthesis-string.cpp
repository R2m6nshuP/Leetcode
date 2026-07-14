class Solution {
public:
    bool checkValidString(string s) {
    int l=0;
    int h=0;
    for( auto i: s){
        if(i=='('){
            l++;
            h++;
        }
        else if(i==')'){
            l--;
            h--;
        }
        else{
            l--;
            h++;
        }
        if(h<0) return 0;
        if(l<0) l=0;

    }
    return l==0;
    }
};