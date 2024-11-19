class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long i = 0, j = 0, sum = 0, mx = 0, sz = nums.size();
        set<int>st;
        map<int, int> mp;

        while(j < nums.size()){
            sum += nums[j], mp[nums[j]]++;
           
            if(mp[nums[j]] > 1) st.insert(nums[j]);

            if(j-i+1 == k){
                if(!st.size()) mx = max(mx, sum);
                
                mp[nums[i]]--;
                sum -= nums[i];

                if(mp[nums[i]] <= 1 && st.find(nums[i]) != st.end())
                    st.erase(nums[i]);
                
                i++;
            }
            j++;
        }
        return mx;
    }
};