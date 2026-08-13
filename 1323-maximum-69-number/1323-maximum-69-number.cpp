class Solution {
public:
    int maximum69Number (int num) {
        int copy=0;
        while(num){
            copy=10*copy+num%10;
            num/=10;
        }
        num=0;
        bool done=0;
        while(copy){
            if(copy%10==6) {
                if(!done) num=10*num+9;
                else num=10*num+6;
                done=1;
            }
            else num=10*num+9;
            copy/=10;
        }
        return num;
    }
};