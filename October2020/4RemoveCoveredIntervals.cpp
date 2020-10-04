class Solution {
public:
    static bool cmp(vector<int> A, vector<int> B){
        if(A[0]==B[0])
            return A[1]>B[1];
        else
            return A[0]<B[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& ins) {
        sort(ins.begin(), ins.end(), cmp);
        int ans=0;
        int s=-1, e=-1;
        for(int i=0; i<ins.size(); ++i){
            if(!(s<=ins[i][0] && e>=ins[i][1])){
                s = ins[i][0];
                e=ins[i][1];
                ans++;
            }
        }
        return ans;
    }
};