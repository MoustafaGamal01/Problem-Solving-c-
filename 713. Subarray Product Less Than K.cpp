class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans(0), l(0), mul(1), x(nums.size());
        if(k <= 1) return 0;
        for(int r = 0; r < x; r++){
            mul *= nums[r];
            while(mul >= k){
                mul /= nums[l];
                l++;
            }
            ans += 1 + (r-l);
        }
        return ans;
    }
};