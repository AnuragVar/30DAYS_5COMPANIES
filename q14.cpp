class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n+1);
        int mod = 1e9 + 7;
        dp[1] = 1;
        long share =0;
        for(int i =2;i<=n;i++){
            dp[i] = share =( share+dp[max(0,i-delay)]-dp[max(0,i-forget)]+mod)%mod;
        }
        long ans = 0;
        int i = max(n-forget+1,0);
        for(;i<=n;i++) ans= (ans+dp[i])%mod;
        return ans;
    }
};