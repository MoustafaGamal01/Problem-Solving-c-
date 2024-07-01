class Solution {
public:
    int DP(int sz, vector<int>&cost,map<int, int>&memo, int i){
        if(i >= sz) return 0;
        if(memo[i] != -1) return memo[i];
        return memo[i] = min(DP(sz, cost, memo, i+1),DP(sz, cost, memo, i+2)) + cost[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int sz = cost.size();
        map<int, int>memo;
        
        for(int i = 0; i < sz; i++)memo[i] = -1;
        return min(DP(sz, cost, memo, 0), DP(sz, cost, memo, 1));
    }
};