class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)  return 0;
        int n = grid[0].size();
        vector<long> temp(n+1, -1);
        vector<vector<long>> dp(m+1, temp);
        return (int) helper(grid, 0, 0, dp);
        return -1;
    }

    long helper(vector<vector<int>>& grid, int i, int j, vector<vector<long>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if(i >= m)    return INT_MAX;
        if(j >= n)    return INT_MAX;
        if(i == m-1 && j == n-1)    return grid[i][j];
        if(dp[i][j] != -1)  return dp[i][j];
        return dp[i][j] = min(helper(grid, i+1, j, dp) + grid[i][j], grid[i][j] + helper(grid, i, j+1, dp));
    }
};
