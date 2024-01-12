class Solution {
public:

    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        vector<int> pre(n+1,0);
        for(int i =0;i<n;i++){
            pre[i+1] = pre[i];
            if(nums[i]%p==0) pre[i+1] += 1;
        }
       
        set<vector<int>> s;
        for(int i =0;i<n;i++){
            for(int j =i;j<n;j++){
                if(pre[j+1]-pre[i]<=k){
                    vector<int> temp;
                    for(int k = i;k<=j;k++){
                        temp.push_back(nums[k]);
                    }
                    s.insert(temp);
                }
            }
        }
        
        return s.size();
    }
};