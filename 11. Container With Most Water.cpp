class Solution {
public:
    int maxArea(vector<int>& height) {
        int x(height.size()), l(0), r(x-1), mx(0);
        while(l < r){
            mx = max(mx, (min(height[l], height[r])) * (r-l));
            height[l] > height[r] ? r-- : l++;
        }
        return mx;
    }
};