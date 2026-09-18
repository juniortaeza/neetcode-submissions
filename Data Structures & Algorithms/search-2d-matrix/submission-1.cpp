class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int l = 0, r = rows*cols - 1;
        while(l <= r){
            int mid = l + (r-l) / 2;
            int midNum = matrix[mid/cols][mid%cols];
            if(midNum == target)
                return true;
            else if(midNum < target)
                l = mid + 1;
            else if(midNum > target)
                r = mid - 1;
        }

        return false;
    }
};
