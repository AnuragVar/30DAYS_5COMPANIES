class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int size = nums[0].size();
        int n =nums.size();
        vector<int> ans;
        for(auto it:queries){
            int digits = it[0];
            int pos = it[1];
            vector<pair<string,int>> temp;
            for(int i =0;i<n;i++){
                temp.push_back({nums[i].substr(size-pos,pos),i});
            }
            sort(temp.begin(),temp.end());
            ans.push_back(temp[digits-1].second);
        }
        return ans;
    }
};