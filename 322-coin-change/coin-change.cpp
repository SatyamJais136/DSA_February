class Solution {
public:
    int rec(int i, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if(amount == 0) return 0; // base case
        if(i >= coins.size() || amount < 0) return 1e9;
        if(dp[i][amount] != -1) return dp[i][amount];
        int take = 1 + rec(i, coins, amount-coins[i], dp);
        int notTake = rec(i+1, coins, amount, dp);
        return dp[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int res =  rec(0, coins, amount, dp);
        return res >= 1e9 ? -1 : res;
    }
};