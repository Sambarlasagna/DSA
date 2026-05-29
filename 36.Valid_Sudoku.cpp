class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {
                    char k = board[i][j];
                    int bi = (i / 3) * 3 + (j / 3);
                    if (rows[i].count(k) || cols[j].count(k) || boxes[bi].count(k))
                    {
                        return false;
                    }
                    rows[i].insert(k);
                    cols[j].insert(k);
                    boxes[bi].insert(k);
                }
            }
        }
        return true;
    }
};

/*
Alternate soln
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                char k = board[i][j];
                if(k!='.'){
                    for(int j1 = 0;j1<9;j1++){
                        if(board[i][j1]==k &&j!=j1){
                            printf("%d %d\n",i,j);
                            printf("%d %d",i,j1);
                            return false;
                        }
                    }
                    for(int i1 = 0;i1<9;i1++){
                        if(board[i1][j]==k && i!=i1){
                            return false;
                        }
                    }
                    if(i<3){
                        if(j<3){
                            for(int i1 = 0;i1<3;i1++){
                                for(int j1 = 0;j1<3;j1++){
                                    if(board[i1][j1]==k && i!=i1 && j!=j1){
                                        return false;
                                    }
                                }
                            }
                        }
                        else if(j<6){
                            for(int i1 = 0;i1<3;i1++){
                                for(int j1 = 3;j1<6;j1++){
                                    if(board[i1][j1]==k && i!=i1 && j!=j1){
                                        return false;
                                    }
                                }
                            }
                        }
                        else if(j<9){
                            for(int i1 = 0;i1<3;i1++){
                                for(int j1 = 6;j1<9;j1++){
                                    if(board[i1][j1]==k && i!=i1 && j!=j1){
                                        return false;
                                    }
                                }
                            }
                        }
                    }
                    else if(i<6){
                        if(j<3){
                            for(int i1 = 3;i1<6;i1++){
                                for(int j1 = 0;j1<3;j1++){
                                    if(board[i1][j1]==k && i!=i1 && j!=j1){
                                        return false;
                                    }
                                }
                            }
                        }
                        else if(j<6){
                            for(int i1 = 3;i1<6;i1++){
                                for(int j1 = 3;j1<6;j1++){
                                    if(board[i1][j1]==k && i!=i1 && j!=j1){
                                        return false;
                                    }
                                }
                            }
                        }
                        else if(j<9){
                            for(int i1 = 3;i1<6;i1++){
                                for(int j1 = 6;j1<9;j1++){
                                    if(board[i1][j1]==k && i!=i1 && j!=j1){
                                        return false;
                                    }
                                }
                            }
                        }
                    }
                    else if(i<9){
                        if(j<3){
                            for(int i1 = 6;i1<9;i1++){
                                for(int j1 = 0;j1<3;j1++){
                                    if(board[i1][j1]==k && i!=i1 && j!=j1){
                                        return false;
                                    }
                                }
                            }
                        }
                        else if(j<6){
                            for(int i1 = 6;i1<9;i1++){
                                for(int j1 = 3;j1<6;j1++){
                                    if(board[i1][j1]==k && i!=i1 && j!=j1){
                                        return false;
                                    }
                                }
                            }
                        }
                        else if(j<9){
                            for(int i1 = 6;i1<9;i1++){
                                for(int j1 = 6;j1<9;j1++){
                                    if(board[i1][j1]==k && i!=i1 && j!=j1){
                                        return false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
*/