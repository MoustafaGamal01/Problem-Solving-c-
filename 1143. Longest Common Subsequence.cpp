class Solution {
public:
    int DP(int i, int j, string &s, string &m, vector<vector<int>>&memo){
        if(i == s.size() || j == m.size()) return 0;
        if(~memo[i][j]) return memo[i][j];

        if(s[i] == m[j]) return memo[i][j] = 1 + DP(i+1, j+1, s, m, memo);
    
        return memo[i][j] = max({DP(i, j+1, s, m, memo), DP(i+1, j, s, m, memo)});
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>memo(text1.size(), vector<int>(text2.size(), -1));
        return DP(0, 0, text1, text2, memo);
    }
};