class Solution {
public:
    vector<string> ans;
    void isValid(int  num){
        int hr=(num>>6);
        int min=(num&63);
        if(hr>=12 || min>=60) return;
        string s="";
        s+=to_string(hr);
        s+= (min<10) ? ":0" : ":";
        s+=to_string(min);
        ans.push_back(s);
    }
    void bitgen(int pos,int n,int k,int num){
        if(k==0){
            isValid(num);
            return;
        }
        if(pos==n) return;
        bitgen(pos+1,n,k-1,(num | (1<<pos)));
        bitgen(pos+1,n,k,num);
    }
    vector<string> readBinaryWatch(int turnedOn) {
        if(turnedOn==0) return {"0:00"};
        if(turnedOn>=9) return ans;
        bitgen(0,10,turnedOn,0);
        return ans;        
    }

};