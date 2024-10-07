class Solution {
public:
    map<int, int>vis;
    void DFS(int r,vector<vector<int>>& v){
        vis[r] = true;  
        
        if(v[r].size() == 0) return;
        
        for(auto &it : v[r]){
            if(!vis[it]){
                DFS(it, v);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int x = rooms.size();
       
        DFS(0, rooms);

        for(int i = 0; i < x; i++)
            if(!vis[i]) return false;

        return true;
    }
};