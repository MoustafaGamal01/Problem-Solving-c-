class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int x = temps.size();
        vector<int>ans(x, 0);
        stack<int>st;

        for(int i = x-1; i >= 0; --i){
            while(!st.empty() && temps[st.top()] <= temps[i]) st.pop();
            
            if(!st.empty()) ans[i] = st.top()-i;

            st.push(i);
        }
        return ans;
    }
};