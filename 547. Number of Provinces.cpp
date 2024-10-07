class Solution {
public:
    vector<bool> vis;
    vector<int>adj[201];

    void DFS(int r){
        vis[r] = true;
        for(auto it : adj[r]){
            if(!vis[it])
                DFS(it);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), ans = 0;
        vis.resize(n+1);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] && i != j)
                    adj[i+1].push_back(j+1), 
                    adj[j+1].push_back(i+1);
            }
        }

        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                ans++;
                DFS(i);
            }
        }

        return ans;
    }
};