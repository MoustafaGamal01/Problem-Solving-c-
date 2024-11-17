class Solution {
public:
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    int n, m;

    bool isValid(int x, int y, int prevValue, vector<vector<int>>& matrix) {
        return (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] > prevValue);
    }

    int DFS(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        if (dp[x][y] != -1) return dp[x][y]; 

        int maxPath = 1; 
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY, matrix[x][y], matrix)) {
                maxPath = max(maxPath, 1 + DFS(newX, newY, matrix, dp));
            }
        }

        return dp[x][y] = maxPath;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1)); 

        int maxPath = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maxPath = max(maxPath, DFS(i, j, matrix, dp));
            }
        }
        return maxPath;
    }
};
