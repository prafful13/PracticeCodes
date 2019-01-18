class Solution {
public:
    bool dfs(int i, int j, vector<vector<char>>& board,int pos, string& word)   {
        if(word[pos]=='\0') return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return false;
        if(word[pos]==board[i][j])  {
            board[i][j] = '*';
            if(dfs(i-1,j,board,pos+1,word)) return true;
            if(dfs(i+1,j,board,pos+1,word)) return true;
            if(dfs(i,j-1,board,pos+1,word)) return true;
            if(dfs(i,j+1,board,pos+1,word)) return true;
            board[i][j] = word[pos];
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if(m == 0)  return false;
        int n = board[0].size();
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(dfs(i,j,board,0,word))
                    return true;
        return false;
    }
};
