class Solution {
public:
    vector<vector<int>> pns;
    void permutations(vector<int> &nums,int i,int n){
        if(i == n){
            pns.push_back(nums);
            return;
        }

        for(int j = i; j<n; j++){
            swap(nums[i],nums[j]);
            permutations(nums,i+1,n);
            swap(nums[j],nums[i]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();

        permutations(nums,0,n);

        return pns;
    }
};