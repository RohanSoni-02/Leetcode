class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int minSum = 0;
        int maxSum = 0;
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            maxSum = max(maxSum + nums[i], nums[i]);
            minSum = min(minSum + nums[i], nums[i]);
            ans = max(ans, maxSum);
        }
        return ans;
    }
};
