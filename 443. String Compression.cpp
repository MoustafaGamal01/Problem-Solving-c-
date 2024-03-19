class Solution {
public:
    int compress(vector<char>& chars) {
        int x = chars.size();
        if(x == 1) return 1;
        int idx(0), cnt(0);
 
        for(int i = 0; i < x;){
           char ch = chars[i];
           cnt = 0;

           while(i < chars.size() && ch == chars[i]) cnt++, i++;

           chars[idx++] = ch;

           if(cnt > 1){
                for(char it: to_string(cnt))
                chars[idx++] = it;
           }
        }

        return idx;
    }
};