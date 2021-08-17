class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(), n=matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m-1][n-1]) // target is smaller than smallest element in matrix
            return false;                                      // or larger than largest element in matrix
        int left=0, right=m*n-1, mid;
        while(left<=right)
        {
            mid=left+(right-left)/2;
            if(matrix[mid/n][mid % n] == target)
                return true;
            else if(matrix[mid/n][mid % n] < target)
                left=mid+1;
            else 
                right=mid-1;
        }
        return false;
    }
};