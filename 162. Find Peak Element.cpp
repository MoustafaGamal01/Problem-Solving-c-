#define ll long long
class Solution {
public:
    int good(ll mid, vector<int>&v){
        if (v[mid-1] < v[mid] && v[mid]>v[mid+1]) return -1;
        if(v[mid] > v[mid+1]) return -2;
        return -3;
    }
    int findPeakElement(vector<int>& v) {
        ll x = v.size();
        if(x == 1 || v[0] > v[1])   return 0;
        if(v[x-1] > v[x-2]) return x-1;

        ll l(1), r(x-2), ans(-1);
        while(l<=r){
            ll mid = (l+r) / 2;   
            if(good(mid, v) == -1) return mid;
            else if(good(mid, v) == -2) r = mid-1;
            else l = mid+1;
        }
        return ans;
    }
};