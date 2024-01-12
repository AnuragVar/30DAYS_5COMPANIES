class Solution {
public:
    void f(int num,int k,int n,vector<int> &temp,auto & ans){
        if(k==0){
            if(n==0){
                ans.push_back(temp);
                return;
            }
            return;
        }
        if(num<=n && num<=9) {
            temp.push_back(num);
            f(num+1,k-1,n-num,temp,ans);
            temp.pop_back();
            f(num+1,k,n,temp,ans);
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        f(1,k,n,temp,ans);
        return ans;
    }
};