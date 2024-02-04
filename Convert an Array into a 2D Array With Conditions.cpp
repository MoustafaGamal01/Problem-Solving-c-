class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int x = nums.size(), mx(0);
        map<int, int>mp;
        for (auto it : nums) {
            mp[it]++;
            mx = max(mx, mp[it]);
        }
        
        vector<vector<int>> ans(mx);
        mp.clear();
        for (int i = 0; i < x; i++) {
            mp[nums[i]]++;
            ans[mp[nums[i]]-1].push_back(nums[i]);
        } 
        return ans;
    }
};
