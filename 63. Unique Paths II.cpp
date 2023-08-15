class Solution {
public:
    int dp[101][101];
    int helper(int i, int j, int n, int m, vector<vector<int>>& obstacleGrid){
        if(i >= m || j >= n || i < 0 || j < 0 || obstacleGrid[i][j] == 1){
            return 0;
        }
        
        if((i==m-1) && (j==n-1)){
            return 1;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int bottom = helper(i+1, j, n, m, obstacleGrid);
        int right = helper(i, j+1, n, m, obstacleGrid);

        return dp[i][j] = bottom + right;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        memset(dp,-1,sizeof(dp));

        return helper(0,0,n,m, obstacleGrid);
    }
};