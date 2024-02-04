class Solution {
public:
    bool isHappy(int n) {
        int m = 7;
        while(m--){
            string str = to_string(n);
            int sum(0);
            for(auto it : str) 
                sum += pow(it - '0', 2);

            n = sum;
            if(n == 89)return false;
            if(n == 1)return true;
        }
        return false;
    }
};