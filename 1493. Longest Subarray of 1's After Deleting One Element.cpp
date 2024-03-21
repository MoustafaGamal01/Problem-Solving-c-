class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int x = nums.size(), cnt(0), ans(0);
        bool ok(false);
        vector<int>pfx(x, 0), sfx(x, 0);

        if(x==1)return 0;

        for (int i = 0; i < x; i++) {
            if (nums[i] == 1) cnt++;
            else cnt = 0, ok = true;
            pfx[i] = cnt;
        }

        cnt = 0;
        for (int i = x - 1; i >= 0; i--) {
            if (nums[i] == 1) cnt++;
            else cnt = 0;
            sfx[i] = cnt;
        }

        for (int i = 0; i < x; i++) {
            if (pfx[i] == 0) {
                if (i == 0) ans = sfx[i + 1];
                else if (i == x - 1) ans = max(ans, pfx[i - 1]);
                else ans = max(ans, sfx[i + 1] + pfx[i - 1]);
            }
        }
        return !ok ? --x : ans;
    }
};
