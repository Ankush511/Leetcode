class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mp;

        for(auto x : nums){
            mp[x]++;
        }

        for(auto x : mp){
            if(x.second > nums.size()/3){
                res.push_back(x.first);
            }
        }

        return res;
    }
};
