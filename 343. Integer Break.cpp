class Solution {
public:
    int dp[59];
    int helper(int n){

        int res = INT_MIN;

        if(dp[n] != -1){
            return dp[n];
        }

        for(int i=1;i<=n-1;i++){
            int product = i * max(n-i,helper(n-i));
            res = max(res,product);
        }
        
        return dp[n] = res;
    }

    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return helper(n);
    }
};