class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++)
            if(checkRow(board,i)==false)
                return false;
        for(int i=0; i<9; i++)
            if(checkCol(board,i)==false)
                return false;
        for(int i=0; i<9; i=i+3)
            for(int j=0; j<9; j=j+3)
                if(checkBox(board,i,j)==false)
                    return false;
        return true; 
    }
    
    bool checkRow(vector<vector<char>>& board, int r)
    {
        int arr[10]={0};
        for(int i=0; i<9; i++)
        {
            if(board[r][i]!='.')
            {
                if(arr[board[r][i]-'0']!=0)
                    return false;
                arr[board[r][i]-'0']=1;
            }
        }
        return true;
    }
    
    bool checkCol(vector<vector<char>>& board, int c)
    {
        int arr[10]={0};
        for(int i=0; i<9; i++)
        {
            if(board[i][c]!='.')
            {
                if(arr[board[i][c]-'0']!=0)
                    return false;
                arr[board[i][c]-'0']=1;
            }
        }
        return true;
    }
    
    bool checkBox(vector<vector<char>>& board, int r, int c)
    {
        int arr[10]={0};
        for(int i=r; i<r+3; i++)
            for(int j=c; j<c+3; j++)
            {
                if(board[i][j]!='.')
                {
                    if(arr[board[i][j]-'0']!=0)
                        return false;
                    arr[board[i][j]-'0']=1;
                }
            }
        return true;
    }
};