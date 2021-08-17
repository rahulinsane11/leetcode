class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) { // T.C.=O(m + log n)
        int m=matrix.size(), n=matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m-1][n-1]) // target is smaller than smallest element in matrix
            return false;                                      // or larger than largest element in matrix
        for(int i=0; i<m; i++)
        {
            if(target <= matrix[i][n-1]) // find the correct row
            {
                for(int j=0; j<n; j++) // use binary search in the correct row
                {
                    int left=0, right=n-1;
                    while(left<=right)
                    {
                        int mid=left+(right-left)/2;
                        if(matrix[i][mid] == target)
                            return true;
                        else if(matrix[i][mid] < target)
                            left=mid+1;
                        else 
                            right=mid-1;
                    }
                }
            }
        }
        return false;
    }
};