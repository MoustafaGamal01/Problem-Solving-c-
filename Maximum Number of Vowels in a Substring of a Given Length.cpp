class Solution {
public:
    bool Good(char ch) {
        return ((ch == 'a') || (ch == 'e') || (ch == 'u')
            || (ch == 'o') || (ch == 'i'));
    }
    int maxVowels(string s, int k) {
        int mx = 0, cnt = 0;
        int x = s.size();
        
        vector<int>prfx(x+1);
        prfx[0] = 0;
        
        for (int i = 0; i < x; i++) {
            if (Good(s[i])) cnt++;
            prfx[i + 1] = cnt;
        }
        
        for (int i = 1; i <= x - (k - 1); i++)
            mx = max(mx, prfx[i + k - 1] - prfx[i - 1]);

        return mx;
    }
};
