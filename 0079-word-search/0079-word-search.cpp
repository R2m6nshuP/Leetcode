class Solution {
public:
    void finder(vector<vector<char>>& board,vector<vector<char>>& copy,string &word,int j,int x,int y,bool &ans){
        if(ans) return;
        if(j==word.size()){
            ans=1;
            return;
        }
        if(y<0 || x<0) return;
        if(y==board[0].size() || x==board.size()) return;
        if(board[x][y]!=word[j]) return;
        board[x][y]='0';
        finder(board,copy,word,j+1,x+1,y,ans);
        finder(board,copy,word,j+1,x,y+1,ans);
        finder(board,copy,word,j+1,x-1,y,ans);
        finder(board,copy,word,j+1,x,y-1,ans);
        if(!ans) board[x][y]=copy[x][y];
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<char>> copy=board;
        bool ans=0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]) {
                    board[i][j]='0';
                    finder(board,copy,word,1,i+1,j,ans);
                    finder(board,copy,word,1,i,j+1,ans);
                    finder(board,copy,word,1,i-1,j,ans);
                    finder(board,copy,word,1,i,j-1,ans);
                    if(!ans) board[i][j]=copy[i][j];
                }
            }
        }
        return ans;
    }
};