class Solution {
public:

    int dp[101][101][201];

    bool helper(string s1, int i, string s2, int j, string s3, int k, int m, int n, int N){
        if(i == m && j == n && k == N){
            return true;
        }
        if(k >= N){
            return false;
        }

        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }

        bool result = false;

        if(s1[i] == s3[k]){
            result = helper(s1,i+1,s2,j,s3,k+1,m,n,N);
        }

        if(result == true){
            return dp[i][j][k] = result;
        }

        if(s2[j] == s3[k]){
            result = helper(s1,i,s2,j+1,s3,k+1,m,n,N);
        }

        return dp[i][j][k] = result;

    }

    bool isInterleave(string s1, string s2, string s3) {

        int m = s1.length(), n = s2.length(), N = s3.length();

        if(m + n != N){
            return false;
        }

        memset(dp,-1,sizeof(dp));

        return helper(s1,0,s2,0,s3,0,m,n,N);
    }
};