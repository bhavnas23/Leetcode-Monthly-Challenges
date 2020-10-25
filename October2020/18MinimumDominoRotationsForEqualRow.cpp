class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        map<int, int> ma, mb, mi;
        for(int i=0; i<A.size(); ++i){
            if(A[i]==B[i])
                mi[A[i]]++;
            else{
                ma[A[i]]++;
                mb[B[i]]++;
            }
        }
        int ans=INT_MAX, n=A.size();
        bool fl=false;
        for(int i=1; i<=6; ++i){
            if(ma[i]+mb[i]+mi[i]==n){
                ans = min(ans, min(n -mi[i] - ma[i], n - mi[i] - mb[i]));
                fl=true;
            }
        }
        
        return fl ? ans : -1;
        
    }
};
