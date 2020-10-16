class Solution {
public:
    static bool cmp(vector<int> a, vector<int>b){
        if(a[0]==b[0])
            return a[1]<b[1];
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()<=0)return 0;sort(points.begin(), points.end(), cmp);
        int s=points[0][0], e=points[0][1];
        int ans=1;
        for(int i=1; i<points.size(); ++i){
            if(e>=points[i][0]){
                s=max(s,points[i][0]);
                e=min(e, points[i][1]);
            }
            else{
                ans++;
                s=points[i][0];
                e=points[i][1];
            }
        }
        return ans;
    }
};
