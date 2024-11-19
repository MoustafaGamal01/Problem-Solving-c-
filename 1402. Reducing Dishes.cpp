class Solution {
public:
    vector<vector<int>> memo;
    int DP(int i, int time, int n, vector<int>& v){
        if(i >= n) return 0;
        if(~memo[i][time]) return memo[i][time];

        int take = (time * v[i]) + DP(i+1, time+1, n, v);
        int leave = DP(i+1, time, n, v);

        return memo[i][time] = max(take, leave);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        memo = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        return DP(0, 1, n, satisfaction);

        /* another solution - O(Nlog(N)) bc of the sorting part
        
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        int cur = 0, mx = 0, total = 0;  
        
        for (int i = n - 1; i >= 0; i--) {
            total += satisfaction[i];      
            cur += total;     
            mx = max(cur, mx); 
        }
        return mx;
        */
    }
};