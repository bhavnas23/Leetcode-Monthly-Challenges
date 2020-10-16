class Solution {
public:

    bool buddyStrings(string A, string B) {
        if(A.size()!=B.size())
            return false;       
        if(A.size()==0)
            return false;
        int n=A.size();
        int cnt=0;
        for(int i=0; i<n; ++i){
            if(A[i]!=B[i])
                cnt++;  
            if(cnt>2)  
                return false;
        }
        if(cnt==1)
            return false;
        if(cnt==0){
            vector<int> v(26,0);
            for(int i=0; i<n; ++i){
                v[A[i]-'a']++;
                if(v[A[i]-'a']>=2){
                    return true;
                }
            }
            return false;
        }
        vector<int> ind;
        for(int i=0; i<n; ++i){
            if(A[i]!=B[i]){
                ind.push_back(i);
            }  
            
        }
        if(A[ind[0]]==B[ind[1]] && B[ind[0]]==A[ind[1]]){
            return true;    
        }
            
        return false;        
    }
};

