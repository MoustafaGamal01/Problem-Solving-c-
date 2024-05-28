class Solution {
public:
    int longestIdealStringRecursive(string& s, int k, int pos, int lastCharIndex, vector<vector<int>>& memo) {
        if (pos == s.length()) return 0;

        if (memo[pos][lastCharIndex] != -1) 
            return memo[pos][lastCharIndex];
 
        int excludeCurr = longestIdealStringRecursive(s, k, pos + 1, lastCharIndex, memo);

        int includeCurr = 0;
        int diff = abs(s[pos] - lastCharIndex - 'a');
        if (diff <= k) {
            includeCurr = max(includeCurr, 1 + longestIdealStringRecursive(s, k, pos + 1, s[pos] - 'a', memo));
        }

        return memo[pos][lastCharIndex] = max(excludeCurr, includeCurr);
    }

    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(26, -1)); 
        int mx=0;
        for(int i=0;i<26;i++){
            mx=max(longestIdealStringRecursive(s,k,0,i,memo),mx);
        }
        return mx;
    }
};