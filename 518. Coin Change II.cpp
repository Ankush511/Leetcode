class Solution {
public:
    int dp[301][5001];
    int helper(int i, int amount, vector<int>& coins){
        int n = coins.size();
        if(amount == 0){
            return 1;
        }
        if(i == n){
            return 0;
        }
        
        if(dp[i][amount] != -1){
            return dp[i][amount];
        }
        if(amount < coins[i]){
            return dp[i][amount] = helper(i+1, amount, coins);
        }

        int take = helper(i, amount - coins[i], coins);
        int skip = helper(i+1, amount, coins);

        return dp[i][amount] = take + skip;
    }

    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return helper(0,amount, coins);
    }
};