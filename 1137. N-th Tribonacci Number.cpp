public class Solution {
    public int DP(int n, Dictionary<int,int>  memo){
        if(n == 0) return n;
        if(memo[n] != -1) return memo[n];

        return memo[n] = DP(n-1, memo)+DP(n-2, memo)+DP(n-3, memo);
    }
    
    public int Tribonacci(int n) {
        Dictionary<int,int> memo = new Dictionary<int,int>();

        for(int i = 0; i <= n; i++) memo[i] = -1;
        memo[0]=0;
        memo[1]=1;
        memo[2]=1;
        return DP(n, memo);
    }
}

