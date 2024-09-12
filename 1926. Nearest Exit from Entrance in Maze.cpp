class Solution {
private:
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, -1, 1 };
    bool isValid(int x, int y, int n, int m, vector<vector<char>>& maze) {
        return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == '.';
    }

public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int x = maze.size(), y = maze[0].size();
        queue<pair<int, int>> q;
        q.push({ entrance[0], entrance[1] });

        maze[entrance[0]][entrance[1]] = '+';

        int ans = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; ++k) {
                auto myPair = q.front();
                q.pop();

                if ((entrance[0] != myPair.first || entrance[1] != myPair.second)
                    && (myPair.second == 0 || myPair.second == y - 1 || myPair.first == x - 1 || myPair.first == 0))
                    return ans;  

                for (int i = 0; i < 4; i++) {
                    int newI = myPair.first + dx[i],
                        newJ = myPair.second + dy[i];

                    if (isValid(newI, newJ, x, y, maze)) {
                        q.push({ newI, newJ });
                        maze[newI][newJ] = '+';  
                    }
                }
            }
            ans++;  
        }
        return -1; 
    }
};
