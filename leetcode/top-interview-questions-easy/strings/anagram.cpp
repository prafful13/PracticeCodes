class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        int i=0;
        while(s[i]!='\0')   {
            arr[s[i]-'a']++;
            i++;
        }
        i=0;
        while(t[i]!='\0')   {
            arr[t[i]-'a']--;
            i++;
        }
        for(i=0;i<26;i++)   if(arr[i]!=0)   return false;
        return true;
    }
};
