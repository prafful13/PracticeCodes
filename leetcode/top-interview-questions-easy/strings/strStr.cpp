class Solution {
public:
    int strStr(string haystack, string needle) {
        int s = haystack.length(), n = needle.length();
        if(n > s)   return -1;
        if(needle == "")    return 0;
        for(int i=0; i<=s-n; i++)
            if(haystack[i] == needle[0])    {
                int flag = 0;
                for(int j=0;j<n;j++)
                    if(haystack[i+j] != needle[j])  {
                        flag = 1;
                        break;
                    }
                if(flag == 0)   return i;
            }
        return -1;
    }
};
