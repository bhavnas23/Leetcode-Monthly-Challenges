class Solution {
public:
    int findPoisonedDuration(vector<int>& ts, int duration) {
        int ans=0;
        if(ts.size()<=0)
            return 0;
        for(int i=0; i<(ts.size()-1); ++i){
            ans += min(duration, ts[i+1]-ts[i]);
        }
        ans+=duration;
        return ans;
    }
};