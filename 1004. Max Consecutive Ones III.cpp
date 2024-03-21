class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int x = nums.size(), mx = 0;
        vector<int>pfxz(x, 0), pfxo(x, 0);
        int mp[100001] = {0};
        int cnt0(0), cnt1(0);
        
        for (int i = 0; i < x; i++) {
            if (!nums[i])cnt0++;
            else cnt1++;
            pfxz[i] = cnt0;
            pfxo[i] = cnt1;
            if (mp[pfxz[i]] == 0) mp[pfxz[i]] = i+1;
        }
        
        for (int i = 0; i < x; i++) {
            if (pfxz[i] <= k) {
                mx = max(mx, pfxo[i] + pfxz[i]);
            }
            else {
                int t = mp[pfxz[i] - k] - 1;
                mx = max(mx, (pfxo[i] + k) - (pfxo[t]));
            }
        }
        return mx;
    }
};
