class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // initialize rows and cols size
        int rows = matrix.size();
        int cols = matrix[0].size();

        // perform binary search - treating matrix as 1D
        int L = 0, R = rows*cols - 1;
        while(L <= R){
            int mid = L + (R-L)/2;
            int midNum = matrix[mid/cols][mid%cols];
            if(midNum < target){
                L = mid + 1;
            } else if(midNum > target){
                R = mid - 1;
            } else {
                return true;
            }

        }

        // return false by default, element not found
        return false;
    }
};

/*

notes:
- each row in matrix is sorted in non-decreasing order
- first integer of every row is greater than the last integer of the previous row
- solve in O(log(m*n))

approach:
- we're guaranteed every row is is sorted in non-decreasing order
- we're guaranteed first integer of every row > last integer of previous row
- we can view this as an ordinary binary search, but taking into
  account which row and column a particular number is in
  because the matrix is 2-Dimensional

steps:
1  2  4  8
10 11 12 13
14 20 30 40

1) flatten the 2D matrix and treat it as 1-Dimensional
2) use left and right pointers (ordinary binary search) to find target
3) calculating mid element for each iteration
    - how to find mid element?
        L + (R-L)/2 won't work for a 2D matrix
        you'll need to figure out which row and column to iterate over
    - how to find row and column?
        - row:
        - col: 

[1 2 4 8] [10 11 12 13] [14 20 30 40]
              M -> (row,col) = (1,1)
              index=5
              row = index / cols
              col = index % cols

rows -> 3 rows
cols -> 4 cols

0 1 2 3 4  5  6  7  8  9  10 11 -> (11-0)/2 = 5
1 2 4 8 10 11 12 13 14 20 30 40
L          M                 R


T: O(log(m*n)) -> searching over m*n elements
S: O(1)        -> no extra memory created

*/
