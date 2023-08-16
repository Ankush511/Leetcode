// BRUTE FORCE APPROACH | TLE 

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> res;
//         int n = nums.size();
        
//         for(int i=0;i<n-k+1;i++){
//             int maxi = INT_MIN;

//             for(int j=i;j<k+i;j++){
//                 maxi = max(maxi, nums[j]);
//             }

//             res.push_back(maxi);
//         }

//         return res;
//     }
// };

// OPTIMIZED APPROACH USING DEQUE | MONOTONIC DECREASING

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int n = nums.size();
        
        deque<int> deq;

        for(int i=0;i<n;i++){

            while(!deq.empty() && deq.front() <= i-k){
                deq.pop_front();
            }

            while(!deq.empty() && nums[i] >= nums[deq.back()]){
                deq.pop_back();
            }

            deq.push_back(i);

            if(i >= k-1){
                res.push_back(nums[deq.front()]);
            }
        }


        return res;
    }
};