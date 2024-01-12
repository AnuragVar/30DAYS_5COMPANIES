class Solution{
public:
int findbit(int x){
        int c=0;
        while(x){
            if((x&1)==1) return c;
            x=x>>1;
            c++;
        }
        return c;
    }
    vector<int> findTwoElement(vector<int> arr, int n) {
        
        int xorr =0;
        for(int i=0;i<n;i++) {
            xorr ^=arr[i];
            xorr ^=(i+1);
        }
        // // cout<<bit<<" ";
        int bit = findbit(xorr);
        // cout<<xorr<<" "<<bit<<endl;
        vector<int> m,s;
        for(int i =0;i<n;i++){
            if((arr[i]&(1<<bit))){
                m.push_back(arr[i]);
            } 
            else s.push_back(arr[i]);
            if((i+1)&(1<<bit))m.push_back(i+1);
            else s.push_back(i+1);
        }
        int a=0,b=0;
        
        for(auto it:m) a=a^it;
        
        for(auto it:s) b=b^it;
        int cnt =0;
        for(int i =0;i<n;i++){
            if(arr[i]==a) cnt++;
            if(cnt==2)return {a,b};
        }
    
        return {b,a};
        
    }
};