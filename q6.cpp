class Solution {
public:
    void f(auto & ans,auto& temp,int in,auto &digits,auto & v){
        if(in>=digits.size()){
            if(temp!="")
            ans.push_back(temp);
            return;
        }
        
        int num = digits[in]-'0';
        for(int i =0;i<v[num].size();i++){
            temp +=v[num][i];
            f(ans,temp,in+1,digits,v);
            temp.pop_back();
        }
        // return;
    }
    vector<string> letterCombinations(string digits) {
        vector<vector<char>> v(10);
        v[2] = {'a','b','c'};
        v[3] = {'d','e','f'};
        v[4] = {'g','h','i'};
        v[5] = {'j','k','l'};
        v[6] = {'m','n','o'};
        v[7] = {'p','q','r','s'};
        v[8] = {'t','u','v'};
        v[9] = {'w','x','y','z'};
        vector<string> ans;
        string temp ="";
        f(ans,temp,0,digits,v);
        
        return ans;
    }
};