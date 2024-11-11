class Solution {
public:
    void getLeftMax(vector<int>&v, vector<int>&height){
        int mx = 0;
        for(int i = 0; i < height.size(); i++){
            mx = max(mx, height[i]);
            v[i] = mx;
        }
    }
    void getRightMax(vector<int>&v, vector<int>&height){
        int mx = 0;
        for(int i = height.size()-1; i >= 0; --i){
            mx = max(mx, height[i]);
            v[i] = mx;
        }
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftMax(n), rightMax(n);
        getLeftMax(leftMax, height);
        getRightMax(rightMax, height);

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += max(0, (min(leftMax[i], rightMax[i]) - height[i]));
        }
        return ans;

    }
};