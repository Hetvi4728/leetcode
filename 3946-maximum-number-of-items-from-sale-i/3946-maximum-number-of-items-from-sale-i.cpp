
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minPrice = INT_MAX;

        vector<int> freeCnt(n, 0);

        for (int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeCnt[i]++;
                }
            }
        }

        const int NEG = -1e9;
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int price = items[i][1];
            int gain = freeCnt[i] + 1;

            for (int c = budget; c >= price; c--) {
                if (dp[c - price] != NEG) {
                    dp[c] = max(dp[c], dp[c - price] + gain);
                }
            }
        }

        int ans = 0;

        for (int c = 0; c <= budget; c++) {
            if (dp[c] != NEG) {
                int extra = (budget - c) / minPrice;
                ans = max(ans, dp[c] + extra);
            }
        }

        return ans;
    }
};
