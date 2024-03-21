class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int x = grid.size(), ans(0);
        map<vector<int>, int>mp;

        for(int i = 0; i < x; i++) mp[grid[i]]++;
        for(int i = 0; i < x; i++) {
            vector<int> v;
            for(int j = 0; j < x; j++) v.push_back(grid[j][i]);
            if(mp.count(v)) ans += mp[v];
        }

        return ans;
    }
};