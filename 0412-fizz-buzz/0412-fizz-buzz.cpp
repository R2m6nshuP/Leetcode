class Solution {
public:
    vector<string> fizzBuzz(int n) {
     vector<string> ans;
     for(int i=1;i<=n;i++){
        if(i%15==0) ans.push_back("FizzBuzz");
        else if(i%3==0) ans.push_back("Fizz");
        else if(i%5==0) ans.push_back("Buzz");
        else {
            string s="";
            int j=i;
            while(j){
                s=string(1,j%10+'0')+s;
                j/=10;
            }
            ans.push_back(s);
        }
     }   
     return ans;
    }
};