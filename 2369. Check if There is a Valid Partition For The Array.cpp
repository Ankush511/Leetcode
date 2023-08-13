class Solution {
public:
    bool helper(int i, vector<int>& nums, int n, vector<int>& dp){
        if(i >= n){
            return true;
        }

        if(dp[i] != -1){
            return dp[i];
        }
        bool res = false;
        if(i+1 < n && nums[i] == nums[i+1]){ // rule 1
            res = helper(i+2,nums,n,dp);
            if(res == true){
                return true;
            }
        }

        if(i+2 < n && nums[i] == nums[i+1] && nums[i+1] == nums[i+2]){ // rule 2
            res = helper(i+3,nums,n,dp);
            if(res == true){
                return true;
            }
        }

        if(i+2 < n && nums[i+1]-nums[i] == 1 && nums[i+2]-nums[i+1] == 1){ // rule 3
            res = helper(i+3,nums,n,dp);
        } 

        return dp[i] = res;
    }

    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return helper(0,nums,n, dp);
    }
};