class Solution {
public:
    vector<int> areas;
    vector<vector<int>> rectcopy;
    Solution(vector<vector<int>>& rects) {
        rectcopy = rects;
        int area =0;
        int n = rects.size();
        for(int i =0;i<n;i++){
            area += (rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1);
            areas.push_back(area);
        }
    }
    
    vector<int> pick() {
        int rnd = rand()%areas.back();
        int ind = upper_bound(areas.begin(),areas.end(),rnd)-areas.begin();

        auto r = rectcopy[ind];
        int x = rand()%(r[2]-r[0]+1)+r[0];
        int y = rand()%(r[3]-r[1]+1)+r[1];
        return {x,y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */