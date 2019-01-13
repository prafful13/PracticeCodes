class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int s = strs.size();
        if(s == 0)  return "";
        string st = "";
        int j = 0;
        while(1)    {
            char c = strs[0][j];
            if(c == '\0')   return st;
            int flag = 0;
            for(int i=1;i<s;i++)    {
                if(strs[i][j] != c) {
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)   return st;
            st += c;
            j++;
        }
    }
};
