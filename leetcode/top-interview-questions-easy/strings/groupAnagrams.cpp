class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for(auto str : strs)    {
            string s = str;
            sort(s.begin(), s.end());
            m[s].push_back(str);
        }
        vector<vector<string>> res;
        for(auto it: m) res.push_back(it.second);
        return res;
    }
};
