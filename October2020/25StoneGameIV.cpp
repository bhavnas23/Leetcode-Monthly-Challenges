class Solution {
public:
    
    int bs(vector<int> &a, int k){
        int n = a.size();
        int l = 0, h = n-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(l==h)
                return h;
            if(k==a[mid])
                return mid;
            else if(mid+1<n && k >= a[mid] && k < a[mid+1])
                return mid;
            else if(k > a[mid] )
                l = mid+1;
            else
                h = mid-1;
        }
        return 0;
    }
    
    
    bool winnerSquareGame(int n) {
        vector<int> dp;
        dp.push_back(0);
        for(int i=1; i*i<=n; ++i){
            dp.push_back(i*i);
        }
        
        int cnt = 0;
        
        while(n){
            int cel = bs(dp, n);
            if(cel==0)
                break;
            n -= dp[cel];
            // cnt+=cel;
            cnt++;
        }
        
        
        
        return cnt%2;
    }
};
