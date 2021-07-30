class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0}; // 9*9 grid to keep count of rows ; initialized by 0's
        int col[9][9]={0}; // 9*9 grid to keep count of columns ; initialized by 0's
        int box[9][9]={0}; // 9*9 grid to keep count of boxes ; initialized by 0's
        // row[x][y]: y keeps track of element with value (y+1) in xth row in original 9*9 grid
        // col[x][y]: y keeps track of element with value (y+1) in xth col in original 9*9 grid
        // box[x][y]: y keeps track of element with value (y+1) in xth box in original 9*9 grid
        int pos, box_index;
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]!='.')
                {
                    pos=board[i][j]-'0'-1; // find vertical position of element in row[][], col[][], box[][]
                    
                    if(row[i][pos]==1) // check row
                        return false;
                    row[i][pos]=1;
                    
                    if(col[j][pos]==1) // check col
                        return false;
                    col[j][pos]=1;
                    
                    box_index=(i/3)*3+j/3;
                    if(box[box_index][pos]==1) // check box
                        return false;
                    box[box_index][pos]=1;
                }
            }
        }
        return true;
    }
};