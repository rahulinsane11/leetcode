class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
    bool solve(vector<vector<char>>& board)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.') // empty cell found
                {
                    for(char c='1'; c<='9'; c++)
                    {
                        if(isValidPos(board,i,j,c)==true)
                        {
                            board[i][j]=c; // fill the current cell with valid element
                            if(solve(board)==true)
                                return true;
                            else
                                board[i][j]='.'; // make the current cell empty
                        }
                    }
                    return false;
                }
            }
        }
        return true; // all the cells are filled with valid elements
    }
    
    bool isValidPos(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i=0; i<9; i++)
        {
            if(board[row][i]==c) // check row
                return false;
            if(board[i][col]==c) //check col
                return false;
            int x = (row/3)*3 + i/3;
            int y = (col/3)*3 + i%3;
            if(board[x][y]==c) // check for box
                return false;
        }
        return true;
    }
};