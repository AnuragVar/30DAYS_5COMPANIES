class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string,vector<int>> m;

        int n = access_times.size();
        for(int i =0;i<n;i++){
            m[access_times[i][0]].push_back(stoi(access_times[i][1]));
        }
        vector<string> ans;
        for(auto it:m){
            vector<int> temp = it.second;
            sort(temp.begin(),temp.end());
            int p = temp.size();
            if(p<3)continue;
            int done =0;
            for(int i =0;i<p-2;i++){
                for(int j = i+2;i<p;i++){
                    if(temp[j]-temp[i]<100){
                        ans.push_back(it.first);
                        done =1;
                        break;
                    }
                    else break;
                }
                if(done==1)break;
            }
        }
        return ans;
    }
};