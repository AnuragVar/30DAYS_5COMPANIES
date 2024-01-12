class DataStream {
public:
    queue<int> q;
    int r;
    int no;
    int cnt=0;
    DataStream(int value, int k) {
        r = value;
        no = k;
    }
    
    bool consec(int num) {
        q.push(num);
        if(num==r) cnt++;
        if(q.size()<no) return false;
        else if(q.size()>no) {
            if(q.front()==r) cnt--;
            q.pop();
        }
        if(cnt==no)return 1;
        return 0;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */