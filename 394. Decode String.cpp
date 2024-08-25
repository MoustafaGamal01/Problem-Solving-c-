class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != ']') {
                st.push(s[i]);
            }
            else{
                string str = "";
                while(st.top() != '['){
                    str = st.top() + str ;
                    st.pop();
                }
                st.pop(); 
                string num = "";
                while(!st.empty() && isdigit(st.top())){
                    num = st.top() + num;
                    st.pop();
                }
                int temp = stoi(num);  
                while(temp--){
                    for(int p = 0; p < str.size() ; p++)
                        st.push(str[p]);
                }
            }
        }
        s = "";
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        return s;
        
    }
};