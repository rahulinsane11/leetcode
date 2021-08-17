class Solution {
public:
    int m1,n1;
    int uniquePaths(int m, int n) {
        m1=m;
        n1=n;
        vector<vector<int>> grid(m,vector<int>(n,-1)); // grid of m*n filled with -1's
        return solve(0,0,grid);
    }
    
    int solve(int i, int j, vector<vector<int>>& grid)
    {
        if(i>=m1 || j>=n1) // Down or Right move leads to out of bounds
            return 0;
        if(i==m1-1 && j==n1-1) // reached the destination
            return 1;
        if(grid[i][j] != -1) // value does not already exists
            return grid[i][j];
        grid[i][j] = solve(i+1,j,grid) + solve(i,j+1,grid);
        return grid[i][j];
    }
};