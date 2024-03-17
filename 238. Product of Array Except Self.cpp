class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int x = nums.size();
        vector<int> prfx(x,1), sfx(x,1);
        for(int i = 0; i < x; ++i){
            if(i) prfx[i] = prfx[i-1] * nums[i];
            else prfx[i] = nums[i];
        }
        for(int i = x-1; i >= 0; --i){
            if(i == x-1) sfx[i] = nums[i];
            else sfx[i] = sfx[i+1] * nums[i];
        }
        for(int i = 0; i < x; i++){
            if(!i) nums[i] = (sfx[i+1]);
            else if(i == x-1) nums[i] = (prfx[i-1]);
            else nums[i] = (sfx[i+1]*prfx[i-1]);
        }
        return nums;
    }
};