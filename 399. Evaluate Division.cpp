class Solution {
public:
    map<string, vector<pair<string, double>>> adj;
    map<string, bool> vis;
    double res = 1;
    double DFS(string st, string end){
        vis[st] = true;
       
        if(!adj.count(st)) return -1.0;

        if(end == st) return res;

        for(auto it: adj[st]){
            if(!vis[it.first]){
                res *= it.second;
                double result = DFS(it.first, end);
                if (result != -1.0) return result; 
                res /= it.second;  
            }
        }
        
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();
        vector<double> ans;
        
        for(int i = 0; i < n; i++){
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }

        for(auto it: queries){
            double dfsResult = DFS(it[0], it[1]);
            ans.push_back(dfsResult);
            res = 1;
            vis.clear();
        }

        return ans;

    }
};
