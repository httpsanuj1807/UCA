#include <bits/stdc++.h>
using namespace std;

int solve(int row, int col, vector<vector<int>> &grid, int n, int m, vector<vector<int>> &dp){

    if(row == n - 1 && col == m - 1){

        return grid[row][col];

    }

    if(dp[row][col] != -1) return dp[row][col];

    int curr = grid[row][col];

    int rightSum = INT_MAX, bottomSum = INT_MAX;


    // checking for right
    if(col + 1 < m){ 

        rightSum = solve(row, col + 1, grid, n, m, dp);

    }

    // checking for bottom
    if(row + 1 < n ){ 

        bottomSum = solve(row + 1, col, grid, n, m, dp);

    }

    int mini = min(rightSum, bottomSum);

    return dp[row][col] = mini + curr;


}


int main()
{

    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 1},
        {0, 0, 0, 1}
        };

    int n = 4;
    int m = 4;  

    vector<vector<int>> dp(n, vector<int> (m, -1));  

    int result = solve(0, 0, grid, n, m, dp);

    cout << result;    

    return 0;
}

