class Solution {
public:
    int dp[101][101];
    int uniquePaths(int m, int n) {
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                dp[i][j]=-1;
        return calcPaths(0,0,m-1,n-1);
    }
    int calcPaths(int i, int j, int m, int n)   {
        if(dp[i][j] != -1)  return dp[i][j];
        if(i>m || i<0 || j<0 || j>n)  return dp[i][j] = 0;
        if(i==m && j==n)    return dp[i][j] = 1;
        return dp[i][j] = calcPaths(i+1, j, m, n) + calcPaths(i, j+1, m, n);
    }
};
