class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k==1) return 0;
        if(k==2 && n>1) return 1;
        if(k==(1<<(n-1))) return !(n&1);
        if(k<=(1<<(n-1))) return kthGrammar(n-1,k);
        else{
            k-=(1<<(n-1));
            return ! kthGrammar(n-1,k);
        }
        return 0;
    }
};

