class Solution {
public:
    bool static cmp(vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int x(points.size()), t(0), ans(1);
        
        sort(points.begin(), points.end(), cmp);
        for(int i = 1; i < x; i++){
            if(points[t][1] < points[i][0]) ans++, t = i;
        }
        return ans;
    }
};