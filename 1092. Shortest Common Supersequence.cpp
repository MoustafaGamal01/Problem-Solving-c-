class Solution {
public:
    int DP(int i, int j, vector<vector<int>>& memo, string& s, string& m) {
        if (i >= s.size() || j >= m.size()) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        if (s[i] == m[j]) 
            return memo[i][j] = 1 + DP(i + 1, j + 1, memo, s, m);

        int op1 = DP(i + 1, j, memo, s, m);
        int op2 = DP(i, j + 1, memo, s, m);

        return memo[i][j] = max(op1, op2);
    }

    void Print(int i, int j, vector<vector<int>>& memo, string& s, string& m, string& res) {
        while (i < s.size() && j < m.size()) {
            if (s[i] == m[j]) {
                res += s[i];
                i++, j++;
            } 
            else if (memo[i + 1][j] > memo[i][j + 1]) i++;
            else j++;
        }
    }

    string shortestCommonSupersequence(string s, string m) {
        int n = s.size(), o = m.size();
        vector<vector<int>> memo(n + 1, vector<int>(o + 1, -1));

        DP(0, 0, memo, s, m);
        string str = "";
        Print(0, 0, memo, s, m, str);

        string ans = "";
        int i = 0, j = 0;
        for (char c : str) {
            while (i < s.size() && s[i] != c) ans += s[i++];
            while (j < m.size() && m[j] != c) ans += m[j++];
            ans += c;
            i++, j++;
        }
        return ans;

        while (i < s.size()) ans += s[i++];
        while (j < m.size()) ans += m[j++];

    }
};
