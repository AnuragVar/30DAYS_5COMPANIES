class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i=0,j=9;
        int n = s.size();
        set<string> ans;
        set<string> temp;
        for(int i =0;i<n-9;i++){
            string a = s.substr(i,10);
            if(temp.find(a)!=temp.end()) ans.insert(a);
            else temp.insert(a);
        }
        vector<string> res;
        for(auto it:ans) res.push_back(it);
        return res;

    }
};