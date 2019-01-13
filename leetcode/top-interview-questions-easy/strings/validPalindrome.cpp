class Solution {
public:
    bool isPalindrome(string s) {
        if(s == "") return true;
        string t;
        for(int i=0, j=0;s[i]!='\0';i++)
            if(s[i] >= 'a' && s[i] <= 'z')  t += s[i];
            else if(s[i] >= 'A' && s[i] <= 'Z') t += (char)tolower(s[i]);
            else if(s[i] >= '0' && s[i] <= '9') t += s[i];
        int i=0, j=t.length()-1;
        while(i<j)
            if(t[i++]!=t[j--])  return false;
        return true;
    }
};
