class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qr, qd;
        int x = senate.size();

        for(int i = 0; i < x; i++)
            (senate[i] == 'R')?qr.push(i):qd.push(i);
        
        while(!qr.empty() && !qd.empty()){
            int r_index = qr.front(), d_index = qd.front();
            qr.pop(), qd.pop();
            (r_index < d_index)? qr.push(r_index + x) : qd.push(d_index + x);
        }
        
        return (qr.size() > qd.size())? "Radiant" : "Dire";
    }
};
// just comment for test