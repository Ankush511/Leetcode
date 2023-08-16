class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        
        for(int i=0;i<n-k+1;i++){
            int maxi = INT_MIN;

            for(int j=i;j<k+i;j++){
                maxi = max(maxi, nums[j]);
            }

            res.push_back(maxi);
        }

        return res;
    }
};