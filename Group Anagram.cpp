class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, bool>mp;
        int x = strs.size();
        vector<pair<string,int>>vp;
        
        for(int i = 0; i < x; i++){
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s] = true;
            vp.push_back({s, i});
        }
        
        sort(vp.begin(), vp.end());
        int t(0), y(mp.size());
        vector<vector<string>>ans(y);

        for(int i = 0; i < x-1; i++){
            if(vp[i].first == vp[i+1].first)
                ans[t].push_back(strs[vp[i].second]);
            else {
                ans[t].push_back(strs[vp[i].second]);
                t++;
            } 
        }

        if(t != y-1) t++;
        ans[t].push_back(strs[vp[x-1].second]);
        return ans;
    
    }
};