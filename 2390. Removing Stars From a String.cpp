class Solution {
public:
    string removeStars(string s) {
        stack<char>st;

        for(auto it: s){
            if(it != '*') st.push(it);
            else{
                st.pop();
            }
        }
        
        s = "";
        while(!st.empty()) s += st.top(), st.pop();
        
        string a = "";
        for(int i = s.size()-1; i >= 0; --i) a += s[i]; 
        return a;
    }
};