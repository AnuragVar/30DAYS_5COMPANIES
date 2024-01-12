string printMinNumberForPattern(string S){
        int last = 1;
        string ans ="";
        int n = S.size();
        for(int i =-1;i<n;i++){
            if(S[i+1]=='D'){
                int cnt = 0;
                while(S[i+1]=='D'){
                    i++;
                    cnt++;
                }
               
                int tobe = last+cnt;
                int top = tobe;
                
                while(tobe>=last){
                    ans +=(tobe+'0');
                    tobe--;
                }
                last = top+1;
            }
            else{
                ans += (last+'0');
                last++;
            }
        }
        return ans;
    }