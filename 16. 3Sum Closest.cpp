class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int x = nums.size(), ans, diff = INT_MAX;
        for(int i = 0; i < x; i++){
            int l(i+1), r(x-1);
            
            while(l < r){
                if(nums[i] + nums[l] + nums[r] == target) return target;

                if(abs(nums[i] + nums[l] + nums[r]-target) < diff)
                    diff = abs(nums[i] + nums[l] + nums[r]-target),
                    ans = nums[i] + nums[l] + nums[r];

                if(nums[i] + nums[l] + nums[r] < target) l++;
                else r--;
            }
        }
        return ans;
    
    }
};