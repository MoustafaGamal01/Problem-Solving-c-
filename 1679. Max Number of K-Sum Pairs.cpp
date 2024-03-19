class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int x = nums.size(), ans = 0;
        /*
        map<int, int>mp;
        for(auto it:nums) mp[it]++;
        
        for(int i = 0; i < x; i++){
            int t = k - nums[i];
            if(t == nums[i]) {
                ans += mp[t]/2;
                mp[t] = 0;
            }
            else {
                ans += min(mp[t], mp[nums[i]]);
                mp[t] = 0, mp[nums[i]] = 0;
            }
        }*/
        sort(nums.begin(), nums.end());
        int l(0), r(x-1);

        while(l < r){
            if(nums[l] + nums[r] == k) l++, r--, ans++;
            else if(nums[l] + nums[r] > k) r--;
            else l++;
        }
        return ans;
    }
};