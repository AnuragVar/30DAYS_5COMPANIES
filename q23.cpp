class Solution {
public:
    string getHint(string secret, string guess) {
        map<int,int> m;
        int n = secret.size();
        int bulls =0;
        for(int i=0;i<n;i++){
            if(secret[i]==guess[i])bulls++;
            else m[secret[i]]++;
        }
        int cows = 0;
        
        for(int i =0;i<n;i++){
            if(guess[i]!=secret[i]){
                if(m[guess[i]]!=0){
                   cows++;
                   m[guess[i]]--;
                }
            }
        }
        string ans ="";
        ans += to_string(bulls);
        ans += 'A';
        ans += to_string(cows);
        ans += 'B';
        return ans;
    }
};