class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        int n = str.length();
        if(n==0)    return 0;
        int curr = 1, max = 1, prev;
        vector<int> lastoccur;

        for(int i=0; i<256; i++) lastoccur.push_back(-1);
        lastoccur[str[0]] = 0;

        for(int i=1; i<n; i++)  {
            if(lastoccur[str[i]] == -1 || i-curr > lastoccur[str[i]])   curr++;
            else    {
                if(curr > max)  max = curr;
                curr = i - lastoccur[str[i]];
            }
            lastoccur[str[i]] = i;
        }

        return max > curr ? max : curr;
    }
};
