class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9]={0};
        bool col[9][9]={0};
        bool box[9][9]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'1';
                    int idx=(i/3)*3+j/3;
                    if(row[i][num] || col[j][num] || box[idx][num]) return 0;
                    row[i][num] = col[j][num] = box[idx][num]=1;
                }
            }
        }
        return 1;
    }
};