class Solution {
public:
    bool static cmp(pair<int, int>&p1, pair<int, int>&p2){
        return p1.first < p2.first;
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int x(nums1.size());
        vector<pair<int,int>> vp;
        for (int i = 0; i < x; ++i) 
            vp.push_back({nums2[i], nums1[i]});

        sort(vp.begin(), vp.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long t(0), res(0);
        for(int i = x-1; i >= 0; --i){
            pq.push(vp[i].second);
            t += vp[i].second;

            if(pq.size()>k){
                t-= pq.top();
                pq.pop();
            }

            if(pq.size() == k)
                res = max(res, t*vp[i].first);

        }
        return res;
    }
};