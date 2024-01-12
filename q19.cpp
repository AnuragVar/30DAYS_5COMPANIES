class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans(img.begin(),img.end());
        int rows = img.size();
        int cols = img[0].size();
        for(int r =0;r<rows;r++){
            for(int c=0 ;c<cols;c++){
                int sum =0;
                int cnt =0;
                for(int k = -1;k<=1;k++){
                    for(int l = -1;l<=1;l++){
                        if(0<=r+k && r+k<rows && 0<=c+l && c+l<cols){
                            sum +=img[r+k][c+l];
                            cnt++;
                        }
                    }
                }
                            // cout<<sum<<" "<<cnt<<" "<<ans[r][c];
                ans[r][c] =  sum;
                ans[r][c] =floor(ans[r][c]/cnt) ;
            }
        }
        return ans;
    }
};