class Solution {
public:
    int DP(int i, bool got, int fee, vector<int>& prices, vector<vector<int>>& memo) {
        if (i == prices.size()) return 0; 
        if (~memo[i][got]) return memo[i][got];
        
        int doNothing = DP(i + 1, got, fee, prices, memo); 

        if (got) {
            int sell = prices[i] - fee + DP(i + 1, false, fee, prices, memo);
            memo[i][got] = max(doNothing, sell);
        } else {
            int buy = -prices[i] + DP(i + 1, true, fee, prices, memo);
            memo[i][got] = max(doNothing, buy);
        }

        return memo[i][got];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return DP(0, false, fee, prices, memo);
    }
};
