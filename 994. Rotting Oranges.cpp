class Solution {
    map<pair<int, int>, bool>vis;
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    bool isValidCell(int i, int j, int x, int y, vector<vector<int>>& grid) {
        if (i >= x || j >= y || i < 0 || j < 0 || vis[{i, j}] == true || grid[i][j] == 0)
            return false;
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int x = grid.size(), y = grid[0].size();
        queue<pair<int, int>>q;
        int cntFresh  = 0;

        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; j++) {
                if (grid[i][j] == 2) {
                    q.push(make_pair(i, j));
                    vis[make_pair(i, j)] = true;
                }
                if (grid[i][j] == 1) cntFresh++;
            }
        }

        // edge cases
        if (!cntFresh) return 0;
        if (q.empty()) return -1;

        int ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int m = 0; m < sz; m++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int newX = i + dx[k];
                    int newY = j + dy[k];
                    if (isValidCell(newX, newY, x, y, grid)) {
                        if (grid[newX][newY] == 1) {
                            --cntFresh;
							if (cntFresh == 0) return ans + 1;
						}
                        q.push({ newX, newY });
                        vis[{newX, newY}] = true;
                    }
                }
            }
            ans++;
        }
       
		if (cntFresh) return -1; // can't rot all oranges
        return ans;
    }
};