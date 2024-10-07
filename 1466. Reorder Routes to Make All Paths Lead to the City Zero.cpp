class Solution {
public:
    vector<bool> vis; 
     vector<vector<pair<int, int>>> adj; 
    int ans = 0;
    void DFS(int r){
        vis[r] = true;
        for(auto it: adj[r]){ 
            if(!vis[it.first]){
                DFS(it.first);
                ans+=it.second;
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vis.resize(n);
        adj.resize(n);
        
        for(auto it:connections){
            adj[it[0]].push_back({it[1], 1}); 
            adj[it[1]].push_back({it[0], 0}); 
        }

        DFS(0);

        return ans;
    }
};