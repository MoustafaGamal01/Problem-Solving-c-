class Solution {
public:
    int DP(int i, int j, const string &word1, const string &word2, vector<vector<int>> &memo) {
        if(i == 0) return j;
        if(j == 0) return i;
        
        if (memo[i][j] != -1) return memo[i][j];
        
        if (word1[i - 1] == word2[j - 1]) 
            return memo[i][j] = DP(i - 1, j - 1, word1, word2, memo);
    
        int ins = DP(i, j - 1, word1, word2, memo);      
        int del = DP(i - 1, j, word1, word2, memo);      
        int rep = DP(i - 1, j - 1, word1, word2, memo);
        
        return memo[i][j] = 1 + min({ins, del, rep});
    }
    
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        
        vector<vector<int>>memo(m + 1, vector<int>(n + 1, -1));
        
        return DP(m, n, word1, word2, memo);
    }
};
