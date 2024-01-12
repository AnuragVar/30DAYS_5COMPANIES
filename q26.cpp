class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0 ;
        for(int i =0;i<n;i++){
            for(int j=i;j<n;j++){
                int flag = 1, last = -1;
                for(int k = 0;k<n;k++){
                    if(k>=i && k<=j) continue;
                    if(nums[k]>last){
                        last = nums[k];
                    }
                    else{
                        flag = 0;
                        break;
                    }
                }
                cnt +=flag;
            }
        }
        return cnt;
    }
};