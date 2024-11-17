class Solution {
public:
    int BinaryS(vector<vector<int>>& items, int s) {
        int l = 0, r = items.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (items[mid][0] <= s) l = mid + 1; 
            else r = mid; 
        }
        return l; 
    }

    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end()); 
        vector<int> ans;
        
        int mx = 0;
        for (int i = 0; i < items.size(); i++) {
            mx = max(mx, items[i][1]); 
            items[i][1] = mx;
        }

        for (int i = 0; i < queries.size(); i++) {
            int idx = BinaryS(items, queries[i]); // upper bound
            idx > 0 ? ans.push_back(items[idx - 1][1]) : ans.push_back(0);
        }
        return ans;
    }
};
