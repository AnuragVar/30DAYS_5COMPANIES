class Solution {
public:
    int dis(int x1,int y1,int x2,int y2){
        return (x1-x2)*(x1-x2) +(y1-y2)*(y1-y2);
    }
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        for(int x=x1;x<=x2;x++){
            for(int y =y1;y<=y2;y++){
                if(dis(x,y,xCenter,yCenter)<=radius*radius) return 1;
            }
        }
        return 0;
    }
};