// Revision Count : 0
// Brute Force Approach : 
// Approach : 1. We will use two nested loops to traverse each element of matrix
//            2. If any cell with indexes i and j contains 0, we will mark all the elements of ith row and jth col with -1 except the cells with value 0
//            3.  Finally we will replace all -1s with 0s

// Time Complexity : O((N*M)*(N + M)) + O(N*M)       {O(N*M)*(N + M))   for traversing each cell and setting rows and col with -1   O(N*M) for replacing -1s with 0s}

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // we are using col 1 because, we can't use matrix[0][0] both first row and first col
        int col1 = 1;
        // setting col1 and matrix[0][0]
        // col1
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                col1 = 0;
                break;
            }
        }

        // matrix[0][0]
        for(int i = 0; i < matrix[0].size(); i++) {
            if(matrix[0][i] == 0) {
                matrix[0][0] = 0;
                break;
            }
        }

        // now, we will set the remaining elements of first row and first col
        // we will traverse whole matrix (excluding the first row and col) and if we find
        // any element 0, we will mark the corresponding index as zero, in the first row and col

        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // now we will mark all those elements as zeroes, whose ith or jth index matches in the first
        // row or first col respectively
         for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[i].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        // finally we will set the first row and first col. i.e. even if matrix[0][0] = 0 then
        // set the whole first row as 0, same for first col in case of col1 = 0
        
        if(matrix[0][0] == 0) {
            for(int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }

        
        if(col1 == 0) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};



// Optimal approach
// Intuition : 1. We are using the first row and first col of the matrix to store which rows and cols should be set to 0 
// 2. We will traverse the whole matrix, except the 0th row and col i.e. from 1st row and 1st col.
// 3. If we find 0 at any index i,j then we will [i][0] = [0][j] = 0;
// 4. In the end we will set all cells 0 if matrix[i][0] or matrix[0][j] is 0. i.e. the first row or first col index corresponding to that index is 0

// Note : There are more details (mentioned in the code) which are not discussed in the intuition. 
// Time Complexity  :  O(2*(N*M))   |   Space Complexity : O(1)


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // we are using col 1 because, we can't use matrix[0][0] both first row and first col
        int col1 = 1;
        // setting col1 and matrix[0][0]
        // col1
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                col1 = 0;
                break;
            }
        }

        // matrix[0][0]
        for(int i = 0; i < matrix[0].size(); i++) {
            if(matrix[0][i] == 0) {
                matrix[0][0] = 0;
                break;
            }
        }

        // now, we will set the remaining elements of first row and first col
        // we will traverse whole matrix (excluding the first row and col) and if we find
        // any element 0, we will mark the corresponding index as zero, in the first row and col

        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // now we will mark all those elements as zeroes, whose ith or jth index matches in the first
        // row or first col respectively
         for(int i = 1; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[i].size(); j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }

        // finally we will set the first row and first col. i.e. even if matrix[0][0] = 0 then
        // set the whole first row as 0, same for first col in case of col1 = 0
        
        if(matrix[0][0] == 0) {
            for(int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }

        
        if(col1 == 0) {
            for(int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
