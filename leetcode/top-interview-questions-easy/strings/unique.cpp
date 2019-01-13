class Solution {
public:
    int firstUniqChar(string s) {
        int i = 0;
        int arr[26] = {0};
        while(s[i]!='\0')   {
            arr[s[i]-'a']++;
            i++;
        }
        i = 0;
        while(s[i]!='\0')   {
            if(arr[s[i]-'a'] == 1)  return i;
            i++;
        }
        return -1;
    }
};
