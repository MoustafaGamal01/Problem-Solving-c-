class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int x = asteroids.size();
        stack<int>st;

        for(int i = 0; i < x; i++){
            int a = asteroids[i];
            st.push(a);

            while (st.size() > 1){
                int top = st.top();
                st.pop();
                int prv = st.top();
                
                if(prv > 0 && top < 0){
                    int pos = abs(top);
                    if(pos > prv) st.pop(), st.push(top);
                    else if(pos == prv) st.pop();
                }
                else{
                    st.push(top);
                    break;
                }
            }

        }

        x = st.size();
        vector<int>ans(x);
        for(int i = x - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};