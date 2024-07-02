class Solution {
    int MOD=1e9+7;
public
    int DP(int n, vectorint&memo) {
        if(n == 1  n == 2) return n;
        if(n == 3) return 5;

        if(memo[n]!=-1) return memo[n];
            
        return memo[n]=((DP(n-1,memo)2) % MOD +(DP(n-3,memo)) % MOD) % MOD;
    }
    int numTilings(int n) {
        vectorintmemo(n+1,-1);

        return DP(n,memo);
    }
};