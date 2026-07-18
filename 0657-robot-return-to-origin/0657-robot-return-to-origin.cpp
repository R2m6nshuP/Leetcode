class Solution {
public:
    bool judgeCircle(string moves) {
     int x=0;
     int y=0;
     for(auto &i : moves){
        if(i=='U') y++;
        else if(i=='D') y--;
        else if(i=='R') x--;
        else if(i=='L') x++;
     }
     return !(x || y);
    }
};