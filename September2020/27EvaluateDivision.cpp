class Solution {
public:
    
    double dfs(vector<vector<pair<bool, double>>> &adj, int x, int y, vector<bool> &visited){
        if(x==y)
            return (double)(1.0);
        if(adj[x][y].first==true){
            return(adj[x][y].second);
        }
        else if(adj[y][x].first==true)
            return(adj[y][x].second);
        else{
            int n = adj[0].size();
            for(int i=0; i<n; ++i){
                if(x!=i && visited[i]==false){
                    if(adj[x][i].first==true){
                        visited[i] = true;
                        double wt = dfs(adj, i, y, visited);
                        if(wt>0){
                            adj[i][y] = make_pair(true, wt);
                            return adj[x][i].second*adj[i][y].second;
                        }
                        
                    }
                }
            }
        }
        return (double)(-1);
    }
    
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& val, vector<vector<string>>& q) {
        int cnt = 0;
        map<string, int> mp;
        for(int i=0; i<eq.size(); ++i){
            if(mp.find(eq[i][0])==mp.end()){
                mp[eq[i][0]] = cnt;
                cnt++;
            }
            if(mp.find(eq[i][1])==mp.end()){
                mp[eq[i][1]] = cnt;
                cnt++;
            }
        }
        
        vector<vector<pair<bool, double>>> adj(cnt, vector<pair<bool, double>>(cnt, make_pair(false, 0.0)));
    
        
        for(int i=0; i<eq.size(); ++i){
            int x = mp[eq[i][0]], y = mp[eq[i][1]];

            adj[x][x] = make_pair(true, 1.0);
            adj[y][y] = make_pair(true, 1.0);
            adj[x][y] = make_pair(true, val[i]);
            adj[y][x] = make_pair(true, ((double)1)/val[i]);
        }
        
        vector<double> ans;

        for(int i=0; i<q.size(); ++i){
            if(mp.find(q[i][0])==mp.end() || mp.find(q[i][1])==mp.end())
                ans.push_back((double)(-1));
            else{
                int x = mp[q[i][0]], y=mp[q[i][1]];
                bool fl=false;
                if(x>y){
                    int t=x;
                    x=y;
                    y=t;
                    fl=true;
                }
                vector<bool> visited(cnt, false);
                visited[x]=true;
                double wt = dfs(adj, x, y, visited);
                if(wt<0)
                    ans.push_back((double)(-1));
                else{
                    if(fl)
                        wt = (double)1/wt;
                    ans.push_back(wt);
                }
            }
        }
        return ans;
    }
};