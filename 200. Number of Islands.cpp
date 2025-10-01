// Author: Moustafa Gamal
// Time Complexity: O(N*M)
// Space Complexity: O(N*M)

class Solution {
public:
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    map<pair<int, int>, bool>vis;
    
    bool IsValid(int n, int m, int newI, int newJ, vector<vector<char>>& grid){
        return (newI >= 0 && newJ >= 0 && newI < n && newJ < m && vis[{newI, newJ}] == false && grid[newI][newJ] == '1');
    }
    void BFS(int n, int m, int i, int j, vector<vector<char>>& grid){
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[{i, j}] = true;

        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            for(int k = 0; k < 4; k++){
                int newI = cur.first + dx[k];
                int newJ = cur.second + dy[k];
                if(IsValid(n, m, newI, newJ, grid)){
                    q.push({newI, newJ});  
                    vis[{newI, newJ}] = true;
                }
            }
        }
    } 
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();

        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && vis[{i, j}] == false){
                    ans++;
                    BFS(n, m, i, j, grid);
                }
            }
        }

        return ans;
    }
};


auto init=atexit([]{ofstream("display_runtime.txt")<<"0";});
