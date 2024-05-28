class Solution {
private:
    void backtrack(vector<vector<int>>& ans, vector<int>& temp, int k, int n, int st) {
        if (n == 0 && k == 0) {
            ans.push_back(temp);
            return;
        }
        
        for (int i = st; i <= 9; ++i) {
            if (i > n) break;
            temp.push_back(i);
            backtrack(ans, temp, k - 1, n - i, i + 1); 
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(ans, temp, k, n, 1);
        return ans;
    }
};