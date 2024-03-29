class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        int i = (temp.size()-1)/2;
        int j = temp.size()-1;
        int k = 0;
        while(k < nums.size())
        {
            if(k&1)
                nums[k++] = temp[j--];
            else
                nums[k++] = temp[i--];
        }
    }
};