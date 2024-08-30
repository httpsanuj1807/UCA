#include <bits/stdc++.h>
using namespace std;

int pickCherries(int row, int col, vector<vector<char>> &grid, int n, int m, vector<vector<int>> &dp){

    if(row >= n - 1 && col >= m - 1){

        return grid[row][col] - '0';

    }

    if(dp[row][col] != -1) return dp[row][col];

    int curr = grid[row][col] - '0';

    int rightSum = INT_MIN, bottomSum = INT_MIN;


    // checking for right
    if(col + 1 < m && grid[row][col + 1] != 'x'){ 

        rightSum = pickCherries(row, col + 1, grid, n, m, dp);

    }

    // checking for bottom
    if(row + 1 < n && grid[row + 1][col] != 'x'){ 

        bottomSum = pickCherries(row + 1, col, grid, n, m, dp);

    }

    int maxi = max(rightSum, bottomSum);

    return dp[row][col] = maxi + curr;

}

int main()
{

    vector<vector<char>> grid = {
        {'0', '0', 'x', 'x'},
        {'1', '0', '1', 'x'},
        {'0', '0', '1', '1'},
        {'0', '0', '1', '0'}};

    int n = 4;
    int m = 4;  

    vector<vector<int>> dp(n, vector<int> (m, -1));  

    int result = pickCherries(0, 0, grid, n, m, dp);

    cout << result;    

    return 0;
}
