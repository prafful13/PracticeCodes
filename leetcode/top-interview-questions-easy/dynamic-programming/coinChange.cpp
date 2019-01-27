class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0);
        // for(int i=0; i<=amount; i++)    dp.push_back(0);
        // sort(coins.begin(), coins.end(), greater<int>());
        return helper(coins, amount, dp);
    }
    int helper(vector<int>& coins, int amount, vector<int>& dp) {
        if(amount < 0)  return -1;
        if(amount == 0) return dp[amount] = 0;
        if(dp[amount] != 0)    return dp[amount];
        int min = INT_MAX;
        for(int i=0; i<coins.size(); i++)   {
            int temp = helper(coins, amount - coins[i], dp);
            if(temp < min && temp >= 0)  min = 1 + temp;
        }
        if(min == INT_MAX)  return dp[amount] = -1;
        return dp[amount] = min;
    }
};
