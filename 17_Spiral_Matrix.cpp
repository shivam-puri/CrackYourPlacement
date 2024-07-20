// Revision Count
// Approach I 
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix[0].size(), n = matrix.size();
        int startRow = 0, startCol = 0, endRow = n-1, endCol = m-1;
        int count = 0;
        vector<int> ans;
        while(count < m * n) {
            for(int i = startCol; i <= endCol && count < m * n; i++) {
                ans.push_back(matrix[startRow][i]);  
                count++;
            }
            startRow++; 
 
            for(int i = startRow; i <= endRow && count < m * n; i++) {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--; 

            for(int i = endCol; i >= startCol && count < m * n; i--) {
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--; 

            for(int i = endRow; i >= startRow && count < m * n; i--) {
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++; 
        }

        return ans;
    }
};


// Approach II
void approachI(vector<vector<int>> &v)
{
    int dr[] = {0, 1, 0, -1};
    int dc[] = {1, 0, -1, 0};
    int dir = 0, x = 0, y = 0;
    int m = v.size(), n = v[0].size();
    vector<vector<bool>> printed(m, vector<bool>(n, false));

    for (int i = 0; i < m * n; i++)
    {

        if (printed[x][y] == false)
        {
            cout << v[x][y] << " ";
            printed[x][y] = true;
        }

        int newX = x + dr[dir];
        int newY = y + dc[dir];

        if (newX >= 0 && newX <= m - 1 && newY >= 0 && newY <= n - 1 &&
            !printed[newX][newY])
        {
            x = newX;
            y = newY;
        }
        else
        {
            dir = (dir + 1) % 4;
            x += dr[dir];
            y += dc[dir];
        }
    }
}