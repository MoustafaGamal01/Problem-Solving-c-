class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int x = nums.size();
        vector<long long>prfx(x, 0);
        if(x == 1) return (double)nums[0];
        for (int i = 0; i < x; i++) {
            if (!i) prfx[i] = nums[i];
            else prfx[i] = prfx[i - 1] + nums[i];
        }

        long long mx = LLONG_MIN;
        for (int i = 0; i+k-1 < x; i++) {
            if (!i) mx = max(mx, prfx[i + k - 1]);
            else mx = max(mx, (prfx[i + k - 1] - prfx[i - 1]));
        }
        return (long double) mx / (k * 1.0);
    }
};
