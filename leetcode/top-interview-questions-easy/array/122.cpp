class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int i = size - 1;
        int dp2[size+2];
        dp2[size] = 0;
        dp2[size+1] = 0;

        while(i>0)  {
            int max = 0;
            for(int j=i+1;j<=size;j++)  {
                int temp = prices[j-1] - prices[i-1] + dp2[j+1];
                if(temp > max)  max = temp;
            }
            if(max < dp2[i+1])  max = dp2[i+1];
            dp2[i] = max;
            i--;
        }
        return dp2[1];
    }

    int maxProfitFaster(std::vector<int>& prices) {
      if (prices.size() <= 1) return 0;
      vector<int> diffs(prices.size() - 1, 0);

      for (int i = 0; i < diffs.size(); i++)
      {
          diffs[i] = prices[i + 1] - prices[i];
          cout<<diffs[i]<<" ";
      }

      int totalProfit = 0;
      // build sum of profits
      for (int i = 0; i < diffs.size(); i++)
      {
          if (diffs[i] > 0)
              totalProfit += diffs[i];
      }
      return totalProfit;
    }
};
