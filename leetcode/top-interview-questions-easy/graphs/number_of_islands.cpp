class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, map<pair<int,int>, bool>& visited, int m, int n) {
        visited[make_pair(i,j)] = true;
        if(i-1 >= 0 && visited[make_pair(i-1,j)] == false && grid[i-1][j] == '1') dfs(i-1, j, grid, visited, m, n);
        if(i+1 < m && visited[make_pair(i+1, j)] == false && grid[i+1][j] == '1') dfs(i+1, j, grid, visited, m, n);
        if(j-1 >= 0 && visited[make_pair(i,j-1)] == false && grid[i][j-1] == '1') dfs(i, j-1, grid, visited, m, n);
        if(j+1 < n && visited[make_pair(i,j+1)] == false && grid[i][j+1] == '1') dfs(i, j+1, grid, visited, m, n);

    }

    int numIslands(vector<vector<char>>& grid) {
        map<pair<int,int>, bool> visited;
        int m = grid.size();
        if(m==0)    return 0;
        int n = grid[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                visited[make_pair(i,j)] = false;
        int ans=0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(visited[make_pair(i,j)]==false && grid[i][j] == '1') {
                    ans++;
                    dfs(i, j, grid, visited, m, n);
                }
        return ans;
    }
};
