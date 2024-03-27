class Solution {
public
    int singleNumber(vectorint& nums) {
        int x = nums.size();
        int ans(0);
        for(int i = 0; i  x; i++)
            ans ^= nums[i];
        
        return ans;
    }
};