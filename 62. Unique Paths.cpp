class Solution {
public:
    int DP(int i, int j, int n, int m, vector<vector<int>>&memo){
        if(i > n || j > m) return 0;
        if(i == n && j == m) return 1;
        if(memo[i][j] != -1) return memo[i][j];

        int w1 = DP(i+1 ,j, n, m, memo);
        int w2 = DP(i, j+1, n, m, memo);

        return memo[i][j] = w1+w2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>memo(n+1, vector<int>(m+1,-1));
        return DP(1, 1, n, m, memo);
    }
};