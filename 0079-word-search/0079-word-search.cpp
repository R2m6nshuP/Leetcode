class Solution {
public:
    void finder(vector<vector<char>>& board,string &word,int j,int x,int y,bool &ans){
        if(ans) return;
        if(j==word.size()){
            ans=1;
            return;
        }
        if(y<0 || x<0) return;
        if(y==board[0].size() || x==board.size()) return;
        if(board[x][y]!=word[j]) return;
        char temp=board[x][y];
        board[x][y]='0';
        finder(board,word,j+1,x+1,y,ans);
        finder(board,word,j+1,x,y+1,ans);
        finder(board,word,j+1,x-1,y,ans);
        finder(board,word,j+1,x,y-1,ans);
        board[x][y]=temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool ans=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]) {
                    char temp=board[i][j];
                    board[i][j]='0';
                    finder(board,word,1,i+1,j,ans);
                    finder(board,word,1,i,j+1,ans);
                    finder(board,word,1,i-1,j,ans);
                    finder(board,word,1,i,j-1,ans);
                    board[i][j]=temp;
                }
            }
        }
        return ans;
    }
};