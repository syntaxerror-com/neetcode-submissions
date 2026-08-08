class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<unordered_set<char>>columns(9);
        vector<unordered_set<char>>rows(9);
        vector<unordered_set<char>>squares(9);

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    continue;
                }
                else{
                    char a =board[i][j];
                    int box=(i/3)*3+(j/3);
                    if(rows[i].find(a)!=rows[i].end()){
                        return false;
                    }
                    else{
                        rows[i].insert(a);
                    }
                    if(columns[j].find(a)!=columns[j].end()){
                        return false;
                    }
                    else{
                        columns[j].insert(a);
                    }
                    if(squares[box].find(a)!=squares[box].end()){
                        return false;
                    }
                    else{
                        squares[box].insert(a);
                    }
                }
            }
        }
        return true;
    }
};
