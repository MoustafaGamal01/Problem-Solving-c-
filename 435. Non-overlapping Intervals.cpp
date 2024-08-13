class Solution {
public:
 static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), cmp);

        int t(0), x(v.size()), ans(0); 
        for(int i = 1; i < x; i++){
            if(v[t][1] > v[i][0]) ans++;
            else t = i;
        }
        return ans;
    }
};