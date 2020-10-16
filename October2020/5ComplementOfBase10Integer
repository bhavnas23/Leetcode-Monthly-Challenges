class Solution {
public:
    int bitwiseComplement(int N) {
        if(N==0)
            return 1;
        int x = N;
        int t=0;
        while(x>0){
            t=(t<<1)+1;
            x=x>>1;
        }
        return (N^t);
    }
};
