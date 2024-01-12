class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        #define goal k
        int cnt = 0;
        for(int it:nums) if(it%2) cnt++;

        vector<int> ones(cnt+2,0);
        int n = nums.size();
        int t =0;
        ones[t++] = -1;
        for(int i=0;i<n;i++){
            if(nums[i]&1) ones[t++] = i; 
        }
        ones[t] = nums.size();
        int ans =0;
        // for(auto it:ones) cout<<it<<" ";
        // cout<<endl;
        if(goal!=0){
        for(int i =1;i<cnt-goal+2;i++){
            int left = ones[i]-ones[i-1];
            int right = ones[i+goal]-ones[i+goal-1];
            cout<<i<<" "<<left<<" "<<right<<endl;
            ans += left*right;
        }
        return ans;
        // }
        // for(int i =1;i<cnt+2;i++){
        //     int w = ones[i]-ones[i-1]-1;
        //     ans+=w*(w+1)/2;
        // }
        // return ans;







        // int n = nums.size();
        
        // vector<pair<int,int>> v;
        // int i =0,j=0;
        // int t = k-1;
        // while(j<n){
        // pair<int,int> a;
        // while(nums[j]%2==0){
        //     j++;
        // }
        // a.first = j-i+1;
        // while(t){
        //     if(nums[j]==1) t--;
        //     j++;
        // }
        // while(j<n && nums[j]%2==0) j++;
        // a.second = j;
        // }


    }
};