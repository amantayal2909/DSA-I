class Solution
{
public:
    int maxProfit(vector<int>& a)
    {
        int n = a.size();

        vector<vector<int>> dp(n + 3, vector<int>(2));

        for(int i = n + 2; i >= n + 1; i--)
        {
            for(int j = 0; i < 2; j++)
                dp[i][j] = 0;

        }

        for(int i = n; i >= 1; i--)
        {
            for(int j = 0; j < 2; j++)
            {
                if(j)
                {
                    int sell = a[i - 1] + dp[i + 2][0];
                    int notSell = dp[i + 1][1];

                    dp[i][j] = max(sell, notSell);

                }

                else
                {
                    int buy = dp[i + 1][1] - a[i - 1];
                    int notBuy = dp[i + 1][0];

                    dp[i][j] = max(buy, notBuy);

                }

            }

        }

        return dp[1][0];

    }
};
