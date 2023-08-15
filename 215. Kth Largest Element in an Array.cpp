class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> pq;
        for(auto i:nums){
            pq.push(i);
        }
        int res=-1;
        if(k<=nums.size()){
            while(k--){
                res=pq.top();
                pq.pop();
            }
        }
        return res;
    }
};