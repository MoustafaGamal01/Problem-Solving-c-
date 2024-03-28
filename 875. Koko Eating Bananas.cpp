class Solution {
private:
    bool good(int mid, vector<int>&v, int h){
        for(int i = 0; i < v.size(); i++)
            h -= ceil((double)v[i]/mid);
        return h >= 0;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l(1), r(1e10);
        while(l <= r){
            int mid = l+(r-l)/2;
            if(good(mid, piles, h)) r=mid-1;
            else l = mid+1;
        }
        return ++r;
    }
};