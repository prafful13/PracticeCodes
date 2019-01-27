class Solution {
public:

    vector<string> letterCombinations(string digits) {
        string arr[] = {" ", "*", "abc", "def", "ghi", "kjl", "mno", "pqrs", "tuv", "wxyz"};
        if(digits.length() == 0)    return {};
        return helper(digits, arr);
    }

    vector<string> helper(string digits, string* arr)    {
        if(digits.length() == 1)    {
            vector<string> ans;
            for(int i=0; i<arr[(digits[0] - '0')].length(); i++)    {
                string temp;
                temp.push_back(arr[(digits[0] - '0')][i]);
                ans.push_back(temp);
            }

            return ans;
        }
        string next = digits.substr(1, digits.length() - 1);
        vector<string> res = helper(next, arr);
        vector<string> ans;

        for(int i=0; i<arr[(digits[0] - '0')].length(); i++)
            for(auto it: res)   {
                string temp;
                temp.push_back(arr[(digits[0] - '0')][i]);
                ans.push_back(temp + it);
            }
        return ans;
    }
};
