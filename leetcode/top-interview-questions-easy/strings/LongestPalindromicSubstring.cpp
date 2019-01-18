class Solution {
public:
    string longestPalindrome(string str) {
        int s = str.length();
        if(s == 0)  return "";
        cout<<s;
        bool dp[s][s];
        for(int i=0;i<s;i++)
            for(int j=0;j<s;j++)
                dp[i][j] = false;
        for(int i=0;i<s;i++)
            dp[i][i] = true;
        int start = 0;
        int max = 1;
        for(int i=0;i<s-1;i++)
            if(str[i] == str[i+1])  {
                dp[i][i+1] = true;
                start = i;
                max = 2;
            }

        for(int k=3; k<=s; k++)    {
            for(int i=0; i<s-k+1; i++)   {
                int j = i + k -1;
                if(dp[i+1][j-1] && str[i]==str[j])  {
                    dp[i][j] = true;
                    start = i;
                    max = k;
                }
            }
        }

        return str.substr(start,max);
    }
};
