class Solution {
public:
    bool check(long long x,long long d1,long long d2,long long u1,long long u2){
        //divisible by d1
        long long A = x/d1;
        long long A_ = x-A;

        //divisible by d2
        long long B = x/d2;
        long long B_ = x-B;

        long long AIB = x/lcm(d1,d2);
        long long AUB = A+B-AIB;
        long long A_IB_ = x-AUB;

        long long needA = ((A_-A_IB_)>=u1)?0:u1-(A_-A_IB_);
        long long needB = ((B_-A_IB_)>=u2)?0:u2-(B_-A_IB_);
        
        if(needA+needB<=A_IB_) return 1;
        return 0;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        
        //applying binary search to find the best answer,
        long long i = 1;
        long long e = 1e17;
        while(i<=e){
            long long m = i+(e-i)/2;
            if(check(m,divisor1,divisor2,uniqueCnt1,uniqueCnt2)){
                e = m-1;
            }
            else{
                i = m+1;
            }
        }
        return i;
    }
};