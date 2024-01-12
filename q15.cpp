class Solution {
public:
    int dp[3001][1001];
    int mod = 1e9+7;
    int f(int s, int e, int k) {
        if (k == 0 && s==e)return 1;
        if(k==0) return 0;
        if(dp[s+1000][k]!=-1) return dp[s+1000][k];

        return dp[s+1000][k] =  (f(s + 1, e, k - 1) % mod + f(s - 1, e, k - 1) % mod) % mod;
        
        
    }

    int numberOfWays(int startPos, int endPos, int k) {
        memset(dp,-1,sizeof(dp));
        return f(startPos, endPos, k);
    }
};